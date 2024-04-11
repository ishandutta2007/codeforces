#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <bitset>
#include <cstdlib>

typedef long long ll;
typedef long double ld;

using namespace std;

int n,k;

const int M=1000000007;


int res;

int dp[3000][2000];

int main()
{
    ios_base::sync_with_stdio(false);

    cin>>n>>k;
    --k;
    dp[0][0]=1;
    for (int i=0;i<n;++i)
    {
        int a;
        cin>>a;
        if (a==0)
        {
            res*=2;
            if (res>=M)
                res-=M;
            for (int x=0;x<1<<k;++x)
            {
                if (x+1==(1<<k))
                {
                    res+=dp[i][x];
                    if (res>=M)
                        res-=M;
                }
                else
                {
                    dp[i+1][x+1]+=dp[i][x];
                    if (dp[i+1][x+1]>=M)
                        dp[i+1][x+1]-=M;
                }
            }



            for (int x=0;x<1<<k;++x)
            {
                if (x&1)
                {
                    dp[i+1][2]+=dp[i][x];
                    if (dp[i+1][2]>=M)
                        dp[i+1][2]-=M;
                }
                else if (x+2==(1<<k))
                {
                    res+=dp[i][x];
                    if (res>=M)
                        res-=M;
                }
                else
                {
                    dp[i+1][x+2]+=dp[i][x];
                    if (dp[i+1][x+2]>=M)
                        dp[i+1][x+2]-=M;
                }
            }
        }
        else if (a==2)
        {
            for (int x=0;x<1<<k;++x)
            {
                if (x+1==(1<<k))
                {
                    res+=dp[i][x];
                    if (res>=M)
                        res-=M;
                }
                else
                {
                    dp[i+1][x+1]+=dp[i][x];
                    if (dp[i+1][x+1]>=M)
                        dp[i+1][x+1]-=M;
                }
            }

        }
        else if (a==4)
        {
            for (int x=0;x<1<<k;++x)
            {
                if (x&1)
                {
                    dp[i+1][2]+=dp[i][x];
                    if (dp[i+1][2]>=M)
                        dp[i+1][2]-=M;
                }
                else if (x+2==(1<<k))
                {
                    res+=dp[i][x];
                    if (res>=M)
                        res-=M;
                }
                else
                {
                    dp[i+1][x+2]+=dp[i][x];
                    if (dp[i+1][x+2]>=M)
                        dp[i+1][x+2]-=M;
                }
            }

        }
    }

    cout<<res;
    return 0;
}