#include<bits/stdc++.h>
using namespace std;
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define rep(i,a,b) for(auto i=a; i<=b; i++)
#define per(i,a,b) for(auto i=b; i>=a; i--)
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
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;

#ifdef CF_DEBUG
 #define debug(...) { cout << "debug : [ "; cout << #__VA_ARGS__; cout << " ] = [ "; W(__VA_ARGS__); cout<<"\b\b ]\n"; }
#else
 #define debug(...) (0)
#endif

const int mod = 1000000007;
const int maxn = 3000;
const int inf = 0x3f3f3f3f;

void chadd(int &x,int y) {x+=y; if(x>=mod) x-=mod;}
void chsub(int &x,int y) {x-=y; if(x<0) x+=mod;}

int a[maxn+5],b[maxn+5];



void solve()
{
	int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    vi odd,even;
    rep(i,1,n) if(i&1) odd.pb(a[i]); else even.pb(a[i]);
    sort(odd.begin(),odd.end());
    sort(even.begin(),even.end());
    rep(i,1,n)
    {
        if(i&1)
        {
            if(odd[i/2]!=i) {puts("-1"); return;}
        }
        else
        {
            if(even[i/2-1]!=i) {puts("-1"); return;}
        }
    }
    vi ans;
    auto find=[&](int x) {
        rep(i,1,n) if(a[i]==x) return i;
        assert(0);
        return -1;
    };
    auto reverse=[&](int x) {
        ans.pb(x);
        rep(i,1,x/2) swap(a[i],a[x+1-i]);
        return;
    };
    for(int i=n;i>1;i-=2)
    {
        int pos=find(i);
        if(pos!=1) reverse(pos);
        pos=find(i-1);
        if(pos!=2)
        {
            reverse(pos-1);
            reverse(pos+1);
            reverse(3);
        }
        reverse(i);
    }
    rep(i,1,n) assert(a[i]==i);
    int N=ans.size(); printf("%d\n",N);
    rep(i,0,N-1) printf("%d%c",ans[i]," \n"[i==N-1]);
}

int main()
{
	int tt=1; scanf("%d",&tt); 
	while(tt--) solve();
	return 0;
}