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
const int maxn = 10000;
const int inf = 0x3f3f3f3f;

struct node {int d,i,j;};
vector<node> q;

bool ok[maxn+5][30];
int a[maxn+5];

void ask(int i,int j)
{
    printf("and %d %d\n",i,j); fflush(stdout);
    int A; scanf("%d",&A);
    printf("or %d %d\n",i,j); fflush(stdout);
    int B; scanf("%d",&B);
    rep(d,0,29)
    {
        if(A>>d&1) ok[i][d]=ok[j][d]=1,a[i]|=1<<d,a[j]|=1<<d;
        else if((B>>d&1)==0) ok[i][d]=ok[j][d]=1;
        else q.pb(node{d,i,j});
    }
}

void solve()
{
	int n,k; scanf("%d%d",&n,&k);
    rep(i,2,n) ask(1,i);
    ask(2,3);
    for(auto [d,i,j]: q)
    {
        assert(ok[i][d] || ok[j][d]);
        if(ok[i][d])
        {
            if((a[i]>>d&1)==0) a[j]|=1<<d;
        }
        else
        {
            if((a[j]>>d&1)==0) a[i]|=1<<d;
        }
        ok[i][d]=ok[j][d]=1;
    } 
    sort(a+1,a+n+1);
    printf("finish %d\n",a[k]); fflush(stdout);
}

int main()
{
	int tt=1; //scanf("%d",&tt); 
	while(tt--) solve();
	return 0;
}