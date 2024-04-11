#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
int n,ans;
char a[100010],b[100010];
int main()
{
    scanf("%d%s%s",&n,a,b);
    for(int i=0;i<n;i++) ans+=min(abs(a[i]-b[i]),10-abs(a[i]-b[i]));
    printf("%d\n",ans);
    return 0;
}