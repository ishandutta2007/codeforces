#include<bits/stdc++.h>
using namespace std;
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define rep(i,a,b) for(auto i=a; i<=b; i++)
#define per(i,a,b) for(auto i=a; i>=b; i--)
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}
template<class T> void _W(const T &x) {cout << x;}
template<class T> void _W(T &x) {cout << x;}
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.first); putchar(' '); _W(x.second);}
template<class T> void _W(const vector<T> &x) {for (auto i = x.begin(); i != x.end(); _W(*i++)) cout<<' ';}
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) {_W(head); cout<<", "; W(tail...);}

#define pb push_back
#define mp make_pair
#define FI first
#define SE second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;

#ifdef CF_DEBUG
 #define debug(...) { cout << "debug : [ "; cout << #__VA_ARGS__; cout << " ] = [ "; W(__VA_ARGS__); cout<<"\b\b ]\n"; }
#else
 #define debug(...) (0)
#endif

const int mod = 1000000007;
const int maxn = 1000;
const int inf = 0x3f3f3f3f;

int a[maxn+5];
ll val[maxn+5],l[maxn+5],r[maxn+5];

void solve()
{
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n) 
    {
        if(i&1) 
        {
            val[i]=val[i-1]+a[i];
            l[i]=val[i-1];
            r[i]=val[i]-1;
        }
        else
        {
            val[i]=val[i-1]-a[i];
            r[i]=val[i-1]-1;
            l[i]=val[i];
        }
    }
    //rep(i,1,n) printf("? %lld %lld\n",l[i],r[i]);
    ull ans=0;
    rep(i,1,n) if(i&1)
    {
        ll mn=1ll<<60;
        rep(j,i+1,n)
        {
            if(j%2==0)
            {
                ll L=max(l[i],l[j]);
                ll R=min(r[i],r[j]);
                chmin(R,mn);
                if(L<=R) ans+=R-L+1;
            }
            chmin(mn,val[j-1]);
            chmin(mn,val[j]);
        }
    }
    printf("%llu\n",ans);
}

int main()
{
	int tt=1; //scanf("%d",&tt); 
	while(tt--) solve();
	return 0;
}