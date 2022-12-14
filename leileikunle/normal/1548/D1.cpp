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
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;

#ifdef CF_DEBUG
 #define debug(...) { cout << "debug : [ "; cout << #__VA_ARGS__; cout << " ] = [ "; W(__VA_ARGS__); cout<<"\b\b ]\n"; }
#else
 #define debug(...) (0)
#endif

const int mod = 1000000007;
const int maxn = 6000;
const int inf = 0x3f3f3f3f;

struct P
{
    int x,y;
    P():x(0),y(0){}
    P(int a,int b):x(a),y(b){}
    void in() {scanf("%d%d",&x,&y);}
    P operator +(const P &a) const {return P(x+a.x,y+a.y);}
    P operator -(const P &a) const {return P(x-a.x,y-a.y);}
};
typedef vector<P> vp;
P a[maxn+5];
int dis[maxn+5][maxn+5];

void solve()
{
    int n; scanf("%d",&n);
    rep(i,1,n) a[i].in(),a[i].x/=2,a[i].y/=2;
    rep(i,1,n) rep(j,i+1,n) dis[i][j]=dis[j][i]=__gcd(abs((a[i]-a[j]).x),abs((a[i]-a[j]).y)) & 1;
    ll cnt1=0,cnt2=0;
    rep(i,1,n) rep(j,i+1,n) cnt1+=1ll*(dis[i][j]==0)*(n-2);
    rep(i,1,n) 
    {
        int cnt=0;
        rep(j,1,n) if(j!=i) cnt+=dis[i][j]==0;
        cnt2+=1ll*cnt*(cnt-1)/2;
    }
    //printf("? %d %d\n",cnt1,cnt2);
    cnt1-=cnt2;
    cnt2/=3;
    printf("%lld\n",cnt1+cnt2);
}  

int main()
{
	int tt=1; //scanf("%d",&tt); 
	while(tt--) solve();
	return 0;
}