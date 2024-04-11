#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define F first
#define S second
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5+100;
const ll INF = 1e9;
const ll kek=998244353;
const ll mod1=1e9+7;
const ll mod2=1e9+9;
const ll mod3=1e18;
const ll p1=1728359;
const ll p2=7245962;
vector <ll> hash1(MAXN);
vector <ll> hash2(MAXN);
vector <ll> hash3(MAXN);
vector <ll> hash4(MAXN);
vector <ll> hash5(MAXN);
vector <ll> hash6(MAXN);
vector <ll> pes(MAXN);
vector <ll> pes1(MAXN);
vector <ll> pes2(MAXN);

void make_p(ll mod,vector <ll> &io, ll p) {
    ll f=1;
    for (int i=0;i<MAXN;i++)
    {
        io[i]=f;
        f*=p;
        f%=mod;
    }
}

void make_hash(vector <ll>  &a,vector <ll> &hash,ll mod,vector <ll> &io)
{
    hash[0]=0;
    for (int i=1;i<=a.size();i++)
    {
        hash[i]=hash[i-1]+(io[i]*a[i-1])%mod;
        hash[i]%=mod;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,w;
    cin>>n>>w;
    hash1.resize(n);
    hash2.resize(w);
    hash3.resize(n);
    hash4.resize(w);
    hash5.resize(n);
    hash6.resize(w);
    make_p(mod1,pes,p1);
    make_p(mod2,pes1,p2);
   // make_p(mod3,pes2,p2);
    vector <ll> prefp(MAXN);
    vector <ll> prefp1(MAXN);
    prefp[0]=0;
    prefp1[0]=0;
    for (int i=1;i<MAXN;i++)
    {
        prefp[i]=prefp[i-1]+pes[i];
    }
    for (int i=1;i<MAXN;i++)
    {
        prefp1[i]=prefp1[i-1]+pes1[i];
    }
    vector <ll> a(n),b(w);
    for (int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        a[i]=x;
    }
    for (int i=0;i<w;i++)
    {
        ll x;
        cin>>x;
        b[i]=x;
    }
    make_hash(a,hash1,mod1,pes);
    make_hash(b,hash2,mod1,pes);
    make_hash(a,hash3,mod2,pes1);
    make_hash(b,hash4,mod2,pes1);
    int ans=0;
    for (int i=1;i<=n-w+1;i++)
    {
        ll q=hash2[w];
        q*=pes[i-1];
        q%=mod1;
        ll x=hash1[i+w-1]-hash1[i-1];
        x%=mod1;
        x+=mod1;
        if (x>=mod1)
            x-=mod1;
        ll t=abs(a[i-1]-b[0]);
        t%=mod1;
        ll f=(prefp[i+w-1]-prefp[i-1]);
        f%=mod1;
        ll l=t*f;
        l%=mod1;
        if (b[0]>=a[i-1])
            x=x+l;
        else
            x=x-l;
        x%=mod1;
        x+=mod1;






        ll g=hash4[w];
        g*=pes1[i-1];
        g%=mod2;
        ll y=hash3[i+w-1]-hash3[i-1];
        y%=mod2;
        y+=mod2;
        if (y>=mod2)
            y-=mod2;
        ll e=abs(a[i-1]-b[0]);
        e%=mod1;
        ll o=prefp1[i+w-1]-prefp1[i-1];
        o%=mod2;
        ll z=o*e;
        z%=mod2;

        if (b[0]>=a[i-1])
            y+=z;
        else
            y-=z;
        y%=mod2;
        y+=mod2;
        if (y>=mod2)
            y-=mod2;


        //cout<<x<<" "<<q<<" "<<y<<" "<<g<<endl;
        if (x>=mod1)
            x-=mod1;
        if (x==q&&y==g) {
            ans++;
            //cout<<i<<endl;
        }

    }
    cout<<ans;
    //ll t=(1e9+7)*(1e9+7);
    //cout<<t;
}