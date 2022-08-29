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
int q[11][11];
int main(){
    //freopen("input.txt","rt",stdin);
   // freopen("output.txt","wt",stdout);
    int n,m,r=0;
    char c;
    scanf("%d %d\n",&n,&m);
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin.get(c);
            if (int(c)==int('P')) q[i][j]=1;
            if (int(c)==int('W')) q[i][j]=2;
        }
        cin.get(c);
    }
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        {
            if (q[i][j]==2)
            {
                if ((i>0 && q[i-1][j]==1) || (j>0 && q[i][j-1]==1) || (i<n-1 && q[i+1][j]==1) || (j<m-1 && q[i][j+1]==1)) r++;
            }
        }
    cout<<r;
    return 0;
}