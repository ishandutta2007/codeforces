#pragma GCC target ("avx2,fma")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int IOS = []() {ios::sync_with_stdio(0); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
template<class T> void _W(const T &x) { cout << x; }
template<class T> void _W(T &x) { cout << x; }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.first); putchar(' '); _W(x.second);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) cout<<' '; }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); cout<<", "; W(tail...); }
#ifdef CF_DEBUG
 #define debug(...) { cout << "debug : [ "; cout << #__VA_ARGS__; cout << " ] = [ "; W(__VA_ARGS__); cout<<"\b\b ]\n"; }
#else
 #define debug(...) (0)
#endif
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define for2(i,a,b) for(int i=a; i<=b;i++)
#define for3(i,a,b) for(int i=a; i>=b;i--)
using ll = long long;
const int N = 1e5+10,mod = 1e9+7;
int a[N];
struct Matrix {
    static const int len = 2;
    int x[len][len];
     
    void init() 
	{
        memset(x, 0, sizeof(x));
        for (int i = 0; i < len; i++)
			x[i][i] = 1;
    }
     
    void zero() {
        memset(x, 0, sizeof(x));
    }
     
    Matrix operator * (const Matrix& m) const {
        Matrix ans;
        ans.zero();
        for (int i = 0; i < len; i++)
            for (int j = 0; j < len; j++)
                for (int k = 0; k < len; k++)
                    ans.x[i][j] = (ans.x[i][j] + x[i][k] * m.x[k][j]) % mod;
        return ans;
    }
     
    Matrix operator + (const Matrix& m) const {
        Matrix ans;
        ans.zero();
        for (int i = 0; i < len; i++)
            for (int j = 0; j < len; j++)
                ans.x[i][j] = (x[i][j] + m.x[i][j]) % mod;
        return ans;
    }
     
    Matrix operator ^ (int b) const {
        Matrix ans, a;
        ans.init();
        memcpy(a.x, x, sizeof(x));
        for (; b; b >>= 1) {
            if(b & 1) ans = ans * a;
            a = a * a;
        }
        return ans;
    }
};
Matrix E,F; // E F 
int a1,a2;
Matrix power(int x)
{
	Matrix b = E,c = F;
	while(x)
	{
		if(x&1) b = b*c;
		c = c*c;
		x>>=1;
	}
	return b;
}
struct node
{
	int l,r;
	Matrix sum,tag;
}tr[N*4];
void pushup(int u)
{
	tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum;
}
void pushdown(int u)
{
	tr[u<<1].sum = tr[u<<1].sum * tr[u].tag;
	tr[u<<1].tag = tr[u<<1].tag * tr[u].tag;
	tr[u<<1|1].sum = tr[u<<1|1].sum * tr[u].tag;
	tr[u<<1|1].tag = tr[u<<1|1].tag * tr[u].tag;
	tr[u].tag = E;
}
void build(int u,int l,int r)
{
	tr[u] = {l,r}; tr[u].tag = E;
	if(l==r)
	{
		tr[u].sum = power(a[l]-1);
		return;
	}
	int mid = l + r>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u);
} 

void update(int u,int l,int r,Matrix x)
{
	if(tr[u].l>=l && tr[u].r<=r)
	{
		tr[u].sum = tr[u].sum * x;
		tr[u].tag = tr[u].tag * x;
		return;
	} 
	pushdown(u);
	int mid = tr[u].l + tr[u].r >>1;
	if(l<=mid) update(u<<1,l,r,x);
	if(r>mid) update(u<<1|1,l,r,x);
	pushup(u);
}
Matrix query(int u,int l,int r)
{
	if(tr[u].l>=l && tr[u].r<=r) return tr[u].sum;
	pushdown(u);
	int mid = tr[u].l + tr[u].r >>1;
	if(r<=mid) return query(u<<1,l,r);
	if(l>mid) return query(u<<1|1,l,r);
	return query(u<<1,l,r)+query(u<<1|1,l,r);
}
void solve()
{
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	a1 = 1,a2 = 1;
	E.x[0][0] = 1;E.x[0][1] = 0; 
	E.x[1][0] = 0;E.x[1][1] = 1;
	F.x[0][0] = 0;F.x[0][1] = 1;
	F.x[1][0] = 1;F.x[1][1] = 1;
	build(1,1,n);
	while(m--)
	{
		int opt; cin>>opt;
		int l,r; cin>>l>>r;
		if(opt==1)
		{
			int x; cin>>x;
			update(1,l,r,power(x));
		}else
		{
			cout<<
			( a1*query(1,l,r).x[0][0]%mod
			+ a2*query(1,l,r).x[1][0]%mod )%mod
			<<endl;
		}
	}
}
signed main()
{
	int tt = 1;
//	cin>>tt;
	while(tt--)
	{
		solve();
	}
}