#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m;
int p[105];
int main()
{
    scanf("%d",&n);
    m=n/2;
    for(int i=1;i<=m;i++) scanf("%d",&p[i]);
    sort(p+1,p+m+1);
    int s1=0,s2=0;
    for(int i=1;i<=m;i++)
    {
        s1+=abs(2*i-p[i]);
        s2+=abs(2*i-1-p[i]);
    }
    printf("%d",min(s1,s2));
    return 0;
}