#include <bits/stdc++.h>
using namespace std;
const int maxn=1000005;
char s[maxn<<1];
int n,len[maxn<<1],pos,k,ans;
void solve()
{
    int i,j,maxx=0,ans=-1,l,r;
    scanf("%s",s);
    n=strlen(s);
    for(i=n-1;i>=0;i--)
    {
        s[(i<<1)|1]=s[i];
        s[i<<1]='#';
    }
    s[n<<1]='#';
    n=n<<1;
    pos=k=ans=0; len[0]=0;
    for(i=1;i<=n;i++)
        if((pos<<1)-i>=0 && len[(pos<<1)-i]+i<k)
            len[i]=len[(pos<<1)-i];
        else
        {
            for(j=k+1;j<=n && (i<<1)-j>=0 && s[j]==s[(i<<1)-j];j++);
            j--;
            pos=i; k=j;
            len[i]=j-i;
        }
    for(i=0;i+1<n-i-1 && s[i+1]==s[n-i-1];i++);
    if(i+1>=n-i-1)
    {
        for(i=1;i<n;i+=2)
            putchar(s[i]);
        putchar('\n');
        return;
    }
    if(s[i]=='#') i--;
    l=i,r=n-i;
    for(i=l+1;i<r;i++)
        if(len[i]>=min(i-l-1,r-i-1))
            maxx=max(maxx,min(len[i],min(i-l-1,r-i-1)));
    for(i=l+1;i<r;i++)
        if(len[i]>=min(i-l-1,r-i-1) && maxx==min(len[i],min(i-l-1,r-i-1)))
            break;
    k=i;
    for(i=1;i<=l;i+=2)
        putchar(s[i]);
    for(i=k-maxx+1;i<k+maxx;i+=2)
        putchar(s[i]);
    for(i=r;i<=n;i+=2)
        putchar(s[i]);
    putchar('\n');
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}