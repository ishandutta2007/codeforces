#include <bits/stdc++.h>
using namespace std;
const int maxn=1000005;
char s[maxn],ans[maxn];
int main()
{
    int i,j,n,m;
    scanf("%s",s),n=strlen(s);
    for(i=0,j=n-1,m=0;j-i>2;i+=2,j-=2)
        if(s[i]==s[j] || s[i]==s[j-1]) ans[m++]=s[i];
        else ans[m++]=s[i+1];
    ans[m]=0; printf("%s",ans);
    if(i<j) printf("%c",s[i]);
    reverse(ans,ans+m);
    printf("%s\n",ans);
    return 0;
}