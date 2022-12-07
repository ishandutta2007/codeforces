#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=300010;
char str[MAXN];
int c[1000],a[1000],tot;
int main()
{
    scanf("%s",str);
    int n=strlen(str);
    for(int i=0;i<n;i++) c[str[i]]++;
    a[++tot]=c['B'];
    a[++tot]=c['u']/2;
    a[++tot]=c['l'];
    a[++tot]=c['b'];
    a[++tot]=c['a']/2;
    a[++tot]=c['s'];
    a[++tot]=c['r'];
    int ans=1000000000;
    for(int i=1;i<=tot;i++) ans=min(ans,a[i]);
    printf("%d\n",ans);
    return 0;
}