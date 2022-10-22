#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#include <assert.h>
#include <bitset>
#define Endl endl
#define mp make_pair
#define ll long long 
#define ull unsinged long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
const int inf=1039074182;
using namespace std;
int dp[200005][1<<8];
int n,m,k;
vector <int> lsh;
int l[100005];
int r[100005];
vector <int> spells[200005];
int sz[200005];
bool Using[200005];
int cp[8];
int maxMask[(1<<8)];

void initPreMask(int now,int pre)
{
	memset(cp,-1,sizeof(cp));
	if(pre==-1)
	{
		return;
	}
	map <int,int> pam;
	for(int i=0;i<sz[pre];i++)
	{
		pam[spells[pre][i]]=i;
	}
	for(int i=0;i<sz[now];i++)
	{
		int spell=spells[now][i];
		if(pam.find(spell)==pam.end()) cp[i]=-1;
		else cp[i]=pam[spell];
	}
}

inline int getPreMask(int mask)
{
	int res=0;
	for(int i=0;i<8;i++)
	{
		if(cp[i]==-1) continue;
		if(!((1<<i) & mask)) continue;
		res|=(1<<cp[i]);
	}
	return res;
}

inline void initMaxMask(int now)
{
	if(now==-1) return;
	memset(maxMask,0,sizeof(maxMask));
	maxMask[0]=0;
	int useMask=0;
	for(int i=0;i<sz[now];i++)
	{
		if(cp[i]==-1) continue;
		useMask|=(1<<cp[i]);
	}
//	if(now==3) cout<<useMask<<endl;
	for(int mask=0;mask<(1<<(now==0?0:sz[now-1]));mask++)
	{
		chmax(maxMask[mask & useMask],dp[now][mask]);
	}
}

inline int getMaxMask(int mask)
{
	return maxMask[mask];
//	return maxMask[(((1<<len)-1) ^ mask)];
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		cin>>l[i]>>r[i];
		r[i]++;
		lsh.push_back(l[i]);
		lsh.push_back(r[i]);
	}
	sort(all(lsh));
	lsh.erase(unique(all(lsh)),lsh.end());
	for(int i=0;i<n;i++)
	{
		l[i]=lower_bound(all(lsh),l[i])-lsh.begin();
		r[i]=lower_bound(all(lsh),r[i])-lsh.begin();
		for(int x=l[i];x<r[i];x++)
		{
			spells[x].push_back(i);
		}
	}
	for(int i=0;i<(int)lsh.size()-1;i++)
	{
		sz[i]=spells[i].size();
	}
	memset(dp,-0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<lsh.size();i++)
	{
		int children=lsh[i]-lsh[i-1];
		initPreMask(i-1,i-2);
		initMaxMask(i-1);
		for(int mask=0;mask<(1<<sz[i-1]);mask++)
		{
			int preMask=getPreMask(mask);
//			if(i==4 && mask==0) cout<<mask<<' '<<preMask<<' '<<maxMask[0]<<endl;
			dp[i][mask]=getMaxMask(preMask)+(__builtin_popcount(mask)&1)*children;
		}
	}
//	cout<<dp[1][1]<<endl;
//	cout<<dp[2][1]<<endl;
//	cout<<dp[3][1]<<endl;
//	cout<<dp[4][0]<<endl;
	int res=0;
	int lastSize=sz[(int)lsh.size()-2];
	int *lastState=dp[(int)lsh.size()-1];
	for(int i=0;i<(1<<lastSize);i++)
	{
		chmax(res,lastState[i]);
	}
	cout<<res<<endl;
	return 0;
}