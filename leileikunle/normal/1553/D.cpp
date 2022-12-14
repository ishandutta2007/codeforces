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
char s[N],t[N];
void solve()
{
	cin>>s+1>>t+1;
	int n = strlen(s+1),m = strlen(t+1);
	if(n<m) 
	{
		cout<<"NO"<<endl;
		return;
	}
	reverse(s+1,s+n+1);
	reverse(t+1,t+m+1);
	for(int i=1,j=1;i<=n&&j<=m;)
	{
		if(s[i]==t[j]) 
		{
			if(j==m) 
			{
				cout<<"YES"<<endl;
				return;
			}else i++,j++;
		}
		if(s[i]!=t[j]) i+=2;
	}
	cout<<"NO"<<endl;
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