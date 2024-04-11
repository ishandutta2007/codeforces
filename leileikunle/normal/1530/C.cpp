#pragma GCC target ("avx2,fma")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int IOS = []() {ios::sync_with_stdio(0); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#define for00 for(int i=1;i<=n;i++) cin>>a[i];
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define for2(i,a,b) for(int i=a; i<=b;i++)
#define for3(i,a,b) for(int i=a; i>=b;i--)
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

const int mod = 1e9+7;

// double time=clock();  printf("%lf\n",clock()-time);


const int N = 2e5+10;
int a[N],b[N],c[N],d[N];
int n;
int q,w;
bool check(int x)
{
	int cun = (x+n)/4;
	if(cun>n)
	{
		if(cun>x)
		{
			if((x+n-cun)*100>=w-d[cun-x]) return true;
			else return false;
		}else
		{
			if((x+n-cun)*100>=w) return true;
			else return false;
		}
		
	}else
	{
		if(cun>x)
		{
			if(q-c[cun]+x*100 >= (w-d[cun-x])) return true;
			else return false;
		}else
		{
			if(q-c[cun]+x*100 >= (w)) return true;
			else return false;
		}
	}
}
bool cmp(int a,int b) 
{
	return a>b; 
}
void solve()
{
	cin>>n;
	q=w=0;
	for(int i=1;i<=n;i++) cin>>a[i],q+=a[i];
	for(int i=1;i<=n;i++) cin>>b[i],w+=b[i];
	sort(a+1,a+n+1); 
	sort(b+1,b+n+1); 
	for(int i=1;i<=n;i++) c[i]=c[i-1]+a[i];
	for(int i=1;i<=n;i++) d[i]=d[i-1]+b[i];
	int l=0,r=3e5+10;
	while(l<r)
	{
		int mid = l + r >>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
	
}
signed main()
{
	int tt=1;
	cin>>tt;
	while(tt--)
	{
		solve();
	}



}