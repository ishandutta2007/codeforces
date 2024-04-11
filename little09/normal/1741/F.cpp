// Author: Little09
// Problem: F. Multi-Colored Segments
// Contest: Codeforces Round #826 (Div. 3)
// URL: https://codeforces.com/contest/1741/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes cout << "Yes" << endl
#define printYES cout << "YES" << endl
#define printNo cout << "No" << endl
#define printNO cout << "NO" << endl
#define endl "\n"
#define lowbit(x) ((x)&(-(x)))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int l[N],r[N],c[N];
int a[N],cnt;
vector<int>t[N];
multiset<int>s;
int ans[N];
ll tree[N];
inline void add(int x,int k)
{
	for (;x<=cnt;x+=lowbit(x)) tree[x]+=k;
}
inline int ask(int x)
{
	int ans=0;
	for (;x;x-=lowbit(x)) ans+=tree[x];
	return ans;
}
void del(int x)
{
	int R=lower_bound(a+1,a+cnt+1,r[x])-a;
	add(R,1);
	int L=lower_bound(a+1,a+cnt+1,l[x])-a;
	add(L,-1);
	s.erase(s.find(l[x]));
	s.erase(s.find(r[x]));
}
void add(int x)
{
	int R=lower_bound(a+1,a+cnt+1,r[x])-a;
	add(R,-1);
	int L=lower_bound(a+1,a+cnt+1,l[x])-a;
	add(L,1);
	s.insert(l[x]);
	s.insert(r[x]);
}
int ask1(int x)
{
	auto u=s.lower_bound(l[x]);
	if (u!=s.end()&&*u<=r[x]) return 0;
	int ww=0;
	int L=lower_bound(a+1,a+cnt+1,l[x])-a;
	if (ask(L-1)) return 0;
	int res=2e9;
	if (u!=s.begin())
	{
		u--;
		res=min(res,l[x]-*u);
	}
	u=s.upper_bound(r[x]);
	if (u!=s.end())
	{
		res=min(res,*u-r[x]);
	}
	return res;
}


void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> l[i] >> r[i] >> c[i];
	cnt=0;
	for (int i=1;i<=n;i++) a[++cnt]=l[i],a[++cnt]=r[i];
	sort(a+1,a+cnt+1);
	for (int i=1;i<=n;i++) t[i].clear();
	for (int i=1;i<=n;i++) t[c[i]].push_back(i);
	for (int i=1;i<=cnt;i++) tree[i]=0;
	s.clear();
	for (int i=1;i<=n;i++)
	{
		add(i);
	}
	for (int i=1;i<=n;i++)
	{
		for (int j:t[i]) del(j);
		for (int j:t[i]) ans[j]=ask1(j);
		for (int j:t[i]) add(j);
	}
	for (int i=1;i<=n;i++) cout << ans[i] << " ";
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) work();
	return 0;
}