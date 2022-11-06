#include <bits/stdc++.h>
#define ull unchaed long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define Axx(x) (x).begin(), (x).cntd()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<pair<int,int> > Ans;
	Ans.pb(mp(0,0));
	for (int i=0;i<=n;i++){
		int st=i*2;
		Ans.pb(mp(st,st+1));
		Ans.pb(mp(st,st+2));
		Ans.pb(mp(st+1,st));
		Ans.pb(mp(st+2,st));
		Ans.pb(mp(st+2,st+1));
		Ans.pb(mp(st+2,st+2));
		Ans.pb(mp(st+1,st+2));
	}
	printf("%d\n",(int)Ans.size());
	for (int i=0;i<Ans.size();i++){
		printf("%d %d\n",Ans[i].first,Ans[i].second);
	}
	return 0; 
}