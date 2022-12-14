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
#define sz(A) (int)A.size()
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
const int maxn = 100000;
const int inf = 0x3f3f3f3f;

int a[maxn+5],b[maxn+5],pos[maxn+5];
int st[maxn+5];
int num[305][305];

void solve()
{
	int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n*m) scanf("%d",&a[i]);
    rep(i,1,n*m) b[i]=a[i];
    sort(b+1,b+n*m+1);
    rep(i,1,n*m) pos[i]=i;
    sort(pos+1,pos+n*m+1,[&](int i,int j) {
        if(b[i]!=b[j]) return b[i]<b[j];
        if((i+m-1)/m==(j+m-1)/m) return i>j;
        return (i+m-1)/m<(j+m-1)/m;
    });
    rep(i,1,n*m) st[i]=0;
    rep(i,1,n*m)
    {
        int A=a[i];
        int rk=lower_bound(b+1,b+n*m+1,A)-b;
        rk=rk+(st[rk]++);
        //printf("? %d: %d %d %d\n",i,a[i],rk,pos[rk]);
        int p=pos[rk];
        int x=(p+m-1)/m,y=p-(x-1)*m;
        num[x][y]=i;
    }
    int cnt=0;
    rep(i,1,n) rep(j,1,m) rep(k,1,j-1) cnt+=num[i][j]>num[i][k];
    printf("%d\n",cnt);
}

int main()
{
	int tt=1; scanf("%d",&tt); 
	while(tt--) solve();
	return 0;
}