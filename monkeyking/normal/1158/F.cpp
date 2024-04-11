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

int n,c;
int w[3005][3005];
int suf0[3005];
int a[3005];
int pow2[3005];
int ipow2[3005];
int dp[3005][3005];
int inv[3005];

int cnt[3005];
int res[3005];

int calc(int l)
{
	memset(cnt,0,sizeof(cnt));
	for(int i=l;i<n;i++) cnt[a[i]]++;
	int res=1;
	for(int i=0;i<c;i++)
	{
		res=1LL*res*(pow2[cnt[i]]-1)%mod;
	}
	res=(pow2[n-l]-res+mod)%mod;
	return res;
}

inline int fastpow(ll basic,int x)
{
	ll res=1;
	while(x)
	{
		if(x&1) (res*=basic)%=mod;
		(basic*=basic)%=mod;
		x>>=1;
	}
	return res;
}

int cur[(1<<8)][3005];
int nxt[(1<<8)][3005];
void bruteforce()
{
	int U=(1<<c)-1;
	cur[0][0]=1;
	for(int i=0;i<n;i++)
	{
		memset(nxt,0,sizeof(nxt));
		for(int mask=0;mask<(1<<c);mask++)
		{
			int nmask=mask|(1<<a[i]);
			for(int j=0;j<=i;j++)
			{
				if(nmask==U) chadd(nxt[0][j+1],cur[mask][j]);else chadd(nxt[nmask][j],cur[mask][j]);
				chadd(nxt[mask][j],cur[mask][j]);
			}
		}
		swap(nxt,cur);
	}
	for(int j=0;j<=n;j++)
	{
		for(int mask=0;mask<(1<<c);mask++)
		{
			chadd(res[j],cur[mask][j]);
		}
	}
}

int main()
{
	// freopen("c.in","r",stdin);
	// freopen("c.out","w",stdout);
	pow2[0]=1;
	for(int i=1;i<=3000;i++) pow2[i]=pow2[i-1]*2%mod;
	for(int i=1;i<=3000;i++) inv[i]=fastpow(i,mod-2);
	for(int i=0;i<=3000;i++) ipow2[i]=fastpow(pow2[i]-1,mod-2);
	cin>>n>>c;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		a[i]--;
	}
	if(c<=8) bruteforce();else{
	for(int l=0;l<n;l++)
	{
		memset(cnt,0,sizeof(cnt));
		int res=1,cnt0=c;
		for(int r=l;r<n;r++)
		{
			if(cnt[a[r]]==0) cnt0--;else res=1LL*res*ipow2[cnt[a[r]]]%mod;
			w[l][r]=(cnt0==0?res:0);
			cnt[a[r]]++;res=1LL*res*(pow2[cnt[a[r]]]-1)%mod;
		}
	}
	for(int i=0;i<=n;i++) suf0[i]=calc(i);
	dp[0][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(!dp[i][j]) continue;
			for(int ed=i+1;ed<=n;ed++)
			{
				chadd(dp[ed][j+1],(int)(1LL*dp[i][j]*w[i][ed-1]%mod));
			}
		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(!dp[i][j]) continue;
			chadd(res[j],(int)(1LL*dp[i][j]*suf0[i]%mod));
		}
	}}
	res[0]--;
	for(int i=0;i<=n;i++)
	{
		printf("%d\n",res[i]);
	}
	return 0;
}