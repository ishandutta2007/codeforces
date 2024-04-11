#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
vector <int> q;
int main(){
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    
    long long n,M=0,m=100000000000;
    cin>>n;
    for (int i=1;i*i<=n;i++)
    {
        if (n%i==0)
        {
            long long nn=n/i;
            for (int ii=1;ii*ii<=nn;ii++)
            {
                if (nn%ii==0)
                {
                    long long a=i,b=ii,c=nn/ii;
                    long long x=(a+1)*(b+2)*(c+2)-n;
                    if (x<m)
                        m=x;
                    if (x>M)
                        M=x;
                    x=(b+1)*(a+2)*(c+2)-n;
                    if (x<m)
                        m=x;
                    if (x>M)
                        M=x;
                    x=(c+1)*(b+2)*(a+2)-n;
                    if (x<m)
                        m=x;
                    if (x>M)
                        M=x;
                }
            }
        }
    }

    cout<<m<<" "<<M;

    return 0;
}