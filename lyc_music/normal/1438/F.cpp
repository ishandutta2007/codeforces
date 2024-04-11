//~~
#define setI(x) freopen(x,"r",stdin)
#define setO(x) freopen(x,"w",stdout)
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
//#define int ll
#define N 1000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int cnt[N],p[N],n;
mt19937_64 rnd(time(0));
bool cmp(int x,int y)
{
    return cnt[x]>cnt[y];
}
void BellaKira()
{
    cin>>n;
    n=(1<<n)-1;
    for (int tm=0;tm<=400;tm++)
    {
        int x=rnd()%n+1,y=rnd()%n+1,z=rnd()%n+1;
        while (x==y||x==z||y==z) x=rnd()%n+1,y=rnd()%n+1,z=rnd()%n+1;
        cout<<"? "<<x<<" "<<y<<" "<<z<<endl;
        cin>>x;
        cnt[x]++;
    }
    for (int i=1;i<=n;i++) p[i]=i;
    sort(p+1,p+n+1,cmp);
    for (int i=1;i<=n;i++)
    {
        if (i==p[1]||i==p[2]) continue;
        cout<<"? "<<p[1]<<" "<<p[2]<<" "<<i<<endl;
        int x=0;
        cin>>x;
        if (x==i) 
        {
            cout<<"! "<<i<<endl;
            return;
        }
    }
}
signed main()
{
    int T=1;
    while (T--)
    {
        BellaKira();
    }
}
/*

*/