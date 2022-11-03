#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int kcz=1000000007;
const int maxn=505;
const int X=4;
const int sz=1<<X;
const int maxx=1<<sz;
char s[maxn];
int p[maxn],sta[maxn],top,f[maxn][maxx|1],tot,temp[2][maxx|1];
int solve(int l,int r)
{
    int id=tot++,i,j,k;
    // printf("%d %d\n",l,r);
    if(l==r)
    {
        int j;
        for(i=0;i<maxx;i++) f[id][i]=0;
        if('A'<=s[l] && s[r]<='D')
        {
            i=0;
            for(j=0;j<sz;j++)
                i|=((j>>(s[l]-'A'))&1)<<j;
            f[id][i]=1;
        }
        else if('a'<=s[l] && s[r]<='d')
        {
            i=0;
            for(j=0;j<sz;j++)
                i|=(!((j>>(s[l]-'a'))&1))<<j;
            f[id][i]=1;
        }
        else
        {
            int k;
            for(k=0;k<X;k++)
            {
                i=0;
                for(j=0;j<sz;j++)
                    i|=((j>>k)&1)<<j;
                f[id][i]=1;
                i=0;
                for(j=0;j<sz;j++)
                    i|=(!((j>>k)&1))<<j;
                f[id][i]=1;
            }
        }
        return id;
    }
    char op=s[p[r]-1];
    int x=solve(l+1,p[r]-3),y=solve(p[r]+1,r-1),mid;
    for(i=0;i<maxx;i++) f[id][i]=0;
    if(op!='|')
    {
        for(i=0;i<maxx;i++) temp[0][i]=f[x][i],temp[1][i]=f[y][i];
        for(i=1;i<=sz;i++)
            for(mid=1<<(i-1),j=0;j<maxx;j+=1<<i)
                for(k=0;k<mid;k++)
                    (temp[0][j|k]+=temp[0][j|k|mid])%=kcz,(temp[1][j|k]+=temp[1][j|k|mid])%=kcz;
        for(i=0;i<maxx;i++) temp[0][i]=temp[0][i]*(ll)temp[1][i]%kcz;
        for(i=1;i<=sz;i++)
            for(mid=1<<(i-1),j=0;j<maxx;j+=1<<i)
                for(k=0;k<mid;k++)
                    (temp[0][j|k]+=kcz-temp[0][j|k|mid])%=kcz;
        for(i=0;i<maxx;i++) (f[id][i]+=temp[0][i])%=kcz;
    }
    if(op!='&')
    {
        for(i=0;i<maxx;i++) temp[0][i]=f[x][i],temp[1][i]=f[y][i];
        for(i=1;i<=sz;i++)
            for(mid=1<<(i-1),j=0;j<maxx;j+=1<<i)
                for(k=0;k<mid;k++)
                    (temp[0][j|k|mid]+=temp[0][j|k])%=kcz,(temp[1][j|k|mid]+=temp[1][j|k])%=kcz;
        for(i=0;i<maxx;i++) temp[0][i]=temp[0][i]*(ll)temp[1][i]%kcz;
        for(i=1;i<=sz;i++)
            for(mid=1<<(i-1),j=0;j<maxx;j+=1<<i)
                for(k=0;k<mid;k++)
                    (temp[0][j|k|mid]+=kcz-temp[0][j|k])%=kcz;
        for(i=0;i<maxx;i++) (f[id][i]+=temp[0][i])%=kcz;
    }
    return id;
}
int main()
{
    int i,lim=0,x=0,q,a,b,c,d,t,ans=0;
    scanf("%s",s);
    top=-1;
    for(i=0;s[i];i++)
        if(s[i]=='(') sta[++top]=i;
        else if(s[i]==')') p[i]=sta[top],top--;
        else p[i]=i;
    tot=0,solve(0,i-1);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&t);
        lim|=1<<(a|(b<<1)|(c<<2)|(d<<3));
        x|=t<<(a|(b<<1)|(c<<2)|(d<<3));
    }
    for(i=0;i<maxx;i++)
        if((i&lim)==x)
            (ans+=f[0][i])%=kcz;
    printf("%d\n",ans);
    return 0;
}