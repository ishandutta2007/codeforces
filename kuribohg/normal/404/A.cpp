#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int n,d,p;
char a[501][501];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    d=a[1][1],p=a[1][2];
    if(d==p) {puts("NO");return 0;}
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i!=j&&i+j!=n+1)
            {
                if(a[i][j]!=p) {puts("NO");return 0;}
                else continue;
            }
            else
            {
                if(a[i][j]!=d) {puts("NO");return 0;}
                else continue;
            }
        }
    puts("YES");
    return 0;
}