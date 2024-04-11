#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <sstream>
#include <assert.h>
#define ll long long 
#define mp(a,b) make_pair(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int inf=1039714778;
const int mod=998244353;
template <typename T> inline void chmin(T &x,const T &b){x=(x<b?x:b);}
template <typename T> inline void chmax(T &x,const T &b){x=(x>b?x:b);}
template <typename T> inline void chadd(T &x,const T &b){x+=b-mod;x+=(x>>31) & mod;}
vector<string> vec_splitter(string s)
{
	s += ',';
	vector<string> res;
	while(!s.empty())
	{
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(vector<string> __attribute__ ((unused)) args,__attribute__ ((unused)) int idx,__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T)
{
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
int T;
int n;
vector<int> edges[500005];
int deg[500005];
int iskey[500005];
char buf[500005];

inline void solve()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) edges[i].clear(),deg[i]=0,iskey[i]=false;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;
		y--;
		edges[x].emplace_back(y);
		edges[y].emplace_back(x);
		deg[x]++;deg[y]++;
	}
	scanf("%s",buf);
	int k=0;
	for(int i=0;i<n;i++)
	{
		if(buf[i]=='W') k++,iskey[i]=true;else iskey[i]=false;
	}
	if(n<=2)
	{
		puts("Draw");
		return;
	}
	if(n==3)
	{
		puts(k>=2?"White":"Draw");
		return;
	}
	vector<int> vcnt3;
	for(int i=0;i<n;i++)
	{
		if(deg[i]>=4)
		{
			puts("White");
			return;
		}
		if(deg[i]==3) vcnt3.emplace_back(i);
	}
	if(vcnt3.size()>=3)
	{
		puts("White");
		return;
	}
	for(auto &x:vcnt3)
	{
		int cntdeg1=0;
		for(auto u:edges[x])
		{
			cntdeg1+=(deg[u]==1);
		}
		if(cntdeg1<2)
		{
			puts("White");
			return;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(deg[i]>=2 && iskey[i])
		{
			puts("White");
			return;
		}
	}
	for(auto &x:vcnt3)
	{
		for(auto u:edges[x])
		{
			if(iskey[u])
			{
				puts("White");
				return;
			}
		}
	}
	int len=n;
	len-=vcnt3.size()*3;
	k+=vcnt3.size();
	if(k<=1)
	{
		puts("Draw");
		return;
	}
	if((len&1)==1) puts("White");else puts("Draw");
}

int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// freopen("a.in","r",stdin);
	// freopen("a.out","w",stdout);
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}