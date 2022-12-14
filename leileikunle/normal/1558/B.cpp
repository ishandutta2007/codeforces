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

int mod;
const int maxn = 4000000;
const int inf = 0x3f3f3f3f;

void chadd(int &x,int y) {x+=y; if(x>=mod) x-=mod;}
void chsub(int &x,int y) {x-=y; if(x<0) x+=mod;}

int ans[maxn+5],ss[maxn+5];

void solve()
{
	int n; scanf("%d%d",&n,&mod);
    ans[n]=ss[n]=1;
    per(i,1,n-1)
    {
        ans[i]=ss[i+1];
        for(int j=2;;j++)
        {
            int l=i*j,r=min(i*j+j-1,n);
            if(l>n) break;
            chadd(ans[i],ss[l]);
            chsub(ans[i],ss[r+1]);
        }
        ss[i]=ss[i+1];
        chadd(ss[i],ans[i]);
    }
    //rep(i,1,n) printf("? %d: %d %d\n",i,ans[i],ss[i]);
    printf("%d\n",ans[1]);
}

int main()
{
	int tt=1; //scanf("%d",&tt); 
	while(tt--) solve();
	return 0;
}