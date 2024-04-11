//xudyh bless me;
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &digit)
{
    digit=0;
    char c;
    for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
    bool type=false;
    if (c=='-')
        type=true,c=getchar();
    for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
    if (type==true)
        digit=-digit;
}

#define maxn 200010
int a[maxn];
int b[maxn],cnt=0;
vector<int> bc[1010];
int now[maxn];
int n;

int gcd(int a,int b)
{
    if (a<b)    swap(a,b);
    if (b==0)   return a;
    return gcd(b,a%b);
}
void prepare()
{
    for (int i=1;i<n;i++)
    if (n%i==0) b[++cnt]=i;
    for (int i=1;i<n;i++)
    {
        int c=gcd(n,i);
        int qqq=lower_bound(b+1,b+cnt+1,c)-b;
        bc[qqq].push_back(i);
    }
}
int main()
{
    read(n);
    for (int i=1;i<=n;i++)  read(a[i]);
    prepare();
    ll ans=0;
    for (int i=1;i<=cnt;i++)
    {
        int hzh=b[i];
        memset(now,0,sizeof(now));
        for (int j=1;j<=n;j++)
        if (now[(j-1)%hzh+1]<a[j])  now[(j-1)%hzh+1]=a[j];
        int sum=0;
        for (int j=1;j<=n;j++)
        if (now[(j-1)%hzh+1]==a[j]) sum++;else sum=0;
        for (int j=n+1;j<=2*n;j++)
        {
            if (now[(j-1)%hzh+1]==a[j-n])   sum++;else sum=0;
            int qqq=lower_bound(bc[i].begin(),bc[i].end(),sum)-bc[i].begin();
            if (bc[i][qqq]==sum)    qqq++;
            ans+=qqq;
        }
    }
    printf("%I64d\n",ans);
    return 0;
}