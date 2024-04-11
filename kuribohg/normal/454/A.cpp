#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n;
char a[110][110];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=(n+1)/2;i++)
        for(int j=1;j<=n;j++)
            if(j<=(n+1)/2-i||j>n/2+i) a[i][j]='*';
            else a[i][j]='D';
    for(int i=(n+1)/2+1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(j<=i-(n+1)/2||j>=n-i+(n+1)/2+1) a[i][j]='*';
            else a[i][j]='D';
    for(int i=1;i<=n;i++) printf("%s\n",a[i]+1);    
    return 0;
}