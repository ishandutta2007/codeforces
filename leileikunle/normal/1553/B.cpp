#pragma GCC target ("avx2,fma")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int IOS = []() {ios::sync_with_stdio(0); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
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


const int N = 2e5+10;
string q,w;
int n,m;
int flag,cnt;
void dfs(int x,int t,int f)
{
//	cout<<x<<" "<<t<<endl;
	if(flag==1||t>m-1) return;
	if(t==m-1&&q[x]==w[t]) 
	{
		flag=1;
		return;
	}
	if(f==0||f==1)
	{
		if(q[x+1]==w[t+1] && x+1<n&&t+1<m) 
		{
			dfs(x+1,t+1,1); 
		}
		if(q[x-1]==w[t+1] && x-1>=0&&t+1<m) 
		{
			dfs(x-1,t+1,2);
		}
	}else
	{
		if(q[x-1]==w[t+1] && x-1>=0&&t+1<m) 
		{
			dfs(x-1,t+1,2);
		}
	}
}
void solve()
{
	cin>>q>>w;
	flag=cnt=0;
	n = q.size(),m = w.size();
	char t = w[0];
	set<int> s;
	for(int i=0;i<n;i++)
	{
		if(q[i]==t) s.insert(i);
	}
	flag=0;
	for(auto k:s)
	{
		dfs(k,0,0);
	}
	if(flag) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
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