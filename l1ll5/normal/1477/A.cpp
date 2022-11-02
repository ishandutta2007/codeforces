#include <bits/stdc++.h>
#define N 300005
#define ll long long
using namespace std;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll d[61];
ll a[N];
void add(ll x)
{
    for(int i=60;i>=0;i--)
    {
        if(x&(1ll<<i))
        {
            if(d[i])x^=d[i];
            else
            {
                d[i]=x;
                break;
            }
        }
    }
}
bool ins(ll x){

    for(int i=60;i>=0;i--)
    {
        if(x&(1ll<<i))
        {
            if(d[i])x^=d[i];
            else
            {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    ll t;
    t=read();
    while(t--) {
        ll n,k;
        for(int i=0;i<=60;i++) d[i]=0;
        n=read(),k=read();
        for(int i=1;i<=n;i++) {
            ll x=read();
            add(x);
            a[i]=x;
        }
        ll tmp = a[2] - a[1];
        for(int i=3;i<=n;i++) tmp = __gcd(tmp, a[1] - a[i] );
        ll h = k - a[1];
        if(h % tmp == 0) puts("YES");
        else puts("NO");
    }
}