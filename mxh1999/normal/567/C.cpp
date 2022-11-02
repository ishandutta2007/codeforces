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
int n,m;
ll sum,ans;
ll g[maxn];
map<int,ll> A,B;

int main()
{
    //freopen("C.in","r",stdin);
    read(n),read(m);
    sum=m;
    sum*=m;
    if (sum>1000000000)
    {
        ll qqq=0;
        for (int i=1;i<=n;i++)
        {
            int x;
            read(x);
            if (x==0)   qqq++;
        }
        ll summ=qqq*(qqq-1)*(qqq-2)/6;
        printf("%I64d\n",summ);
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        read(a[i]);
        if (a[i]!=0 && a[i]%sum==0) ans+=B[a[i]/m];
        if (a[i]!=0 && a[i]%m==0)   B[a[i]]+=A[a[i]/m];
        A[a[i]]++;
    }
    ll qqq=A[0];
    ll summ=qqq*(qqq-1)*(qqq-2)/6;
    ans+=summ;
    printf("%I64d\n",ans);
    return 0;
}