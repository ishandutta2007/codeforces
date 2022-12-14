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
const int N = 1e6+10;
int f1[N],f2[N];
int find1(int x)
{
	return f1[x]==x?x:f1[x] = find1(f1[x]);
}
int find2(int x)
{
	return f2[x]==x?x:f2[x] = find2(f2[x]);
}
vector<int> v1,v2;
pair<int,int> ans[N];
void solve()
{
	int n,m1,m2; cin>>n>>m1>>m2;
	for(int i=1;i<=n;i++) f1[i]=f2[i]=i;
	for(int i=1;i<=m1;i++)
	{
		int u,v; cin>>u>>v;
		if(find1(u)!=find1(v)) f1[find1(u)] = find1(v);
	}
	for(int i=1;i<=m2;i++)
	{
		int u,v; cin>>u>>v;
		if(find2(u)!=find2(v)) f2[find2(u)] = find2(v);
	}
	int idx = 0;
	
	for(int i=2;i<=n;i++)
	{
		int u = find1(1),v = find1(i);
		int x = find2(1),y = find2(i);
		if(u!=v && x!=y)
		{
			f1[u] = v, f2[x] = y;
			ans[++idx] = {1,i};
		}else if(u!=v) v1.push_back(i);
		else v2.push_back(i);
	}
	
	for(int i=0,j=0;i<v1.size()&&j<v2.size();)
	{
		if(find1(1)==find1(v1[i])) 
		{
			i++;
			continue;
		}
		if(find2(1)==find2(v2[j])) 
		{
			j++;
			continue;
		}
		ans[++idx] = {v1[i],v2[j]};
		f1[find1(v1[i])] = find1(v2[j]);
		f2[find2(v1[i])] = find2(v2[j]);
	}
	cout<<idx<<endl;
	for(int i=1;i<=idx;i++)
	{
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
}
signed main()
{
	int tt=1;
//	cin>>tt;
	while(tt--)
	{
		solve();
	}



}