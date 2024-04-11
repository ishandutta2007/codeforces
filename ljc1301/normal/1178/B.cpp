#include <bits/stdc++.h>
using namespace std;
const int maxn=1000005;
char s[maxn],t[maxn];
int pre[maxn];
int main()
{
    int i,n;
    long long ans=0;
    scanf("%s",s);
    for(i=0,n=0;s[i];i++)
    {
        if(s[i]=='v' && s[i+1]=='v') t[n++]='w';
        else if(s[i]=='o') t[n++]='o';
    }
    pre[0]=t[0]=='w';
    for(i=1;i<n;i++) pre[i]=pre[i-1]+(t[i]=='w');
    for(i=0;i<n;i++)
        if(t[i]=='o')
            ans+=pre[i]*(long long)(pre[n-1]-pre[i]);
    printf("%lld\n",ans);
    return 0;
}