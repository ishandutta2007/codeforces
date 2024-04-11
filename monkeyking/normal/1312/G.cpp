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
//#include <self/debug>
#define Endl endl
#define mp make_pair
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define quickcin ios_base::sync_with_stdio(false);
const int mod=1e9+7;
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
using namespace std;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
const int END=inf;
int q;
int trie[1000005][27];
int cnt[1000005];
int n;
int l[1000005];
int r[1000005];
int dp[1000005];
bool inS[1000005];
vector <int> lsh;
int dat[1000005];

template <typename T>
struct SegmentTreeMinInterval//[)
{
	T* data;
	T* tag;
	int nn;
	int size()
	{
		return nn;
	}
	void init(int size)
	{
		nn=1;
		while(nn<size)
		{
			nn<<=1;
		}
		data=new T[nn*2+5];
		tag=new T[nn*2+5];
		for(int i=0;i<=nn*2;i++)
		{
			data[i]=inf;
			tag[i]=inf;
		}
	}
	void pushdown(int x)
	{
		if(x>=nn) return;
		data[x*2]=min(data[x*2],tag[x]);
		data[x*2+1]=min(data[x*2+1],tag[x]);
		tag[x*2]=min(tag[x*2],tag[x]);
		tag[x*2+1]=min(tag[x*2+1],tag[x]);
		tag[x]=inf;//warning
	}
	void update(int ql,int qr,T value)
	{
		update(1,0,nn,ql,qr,value);
	}
	void update(int x,int l,int r,int ql,int qr,T value)
	{
		if(l>=qr || r<=ql) return;
		pushdown(x);
		if(l>=ql && r<=qr)
		{
			data[x]=min(data[x],value);
			tag[x]=min(tag[x],value);
			return;
		}
		update(x*2,l,l+r>>1,ql,qr,value);
		update(x*2+1,l+r>>1,r,ql,qr,value);
		data[x]=min(data[x*2],data[x*2+1]);
	}
	T query(int ql,int qr)
	{
		return query(1,0,nn,ql,qr);
	}
	T query(int x,int l,int r,int ql,int qr)
	{
		if(l>=qr || r<=ql) return inf;
		pushdown(x);
		if(l>=ql && r<=qr)
		{
			return data[x];
		}
		return min(query(x*2,l,l+r>>1,ql,qr),query(x*2+1,l+r>>1,r,ql,qr));
	}
};
SegmentTreeMinInterval <int> sgt;

int go(int x)
{
	cnt[x]=(trie[x][0]==END);
	for(int i=1;i<=26;i++)
	{
		if(trie[x][i]==-1) continue;
		cnt[x]+=go(trie[x][i]);
	}
	return cnt[x];
}

int go2(int x,int pSum=0)
{
//	cout<<x<<'-'<<pSum<<endl;
	l[x]=inf;
	if(trie[x][0]==END) l[x]=pSum,pSum++;
	for(int i=1;i<=26;i++)
	{
		if(trie[x][i]==-1) continue;
		if(l[x]==inf) l[x]=go2(trie[x][i],pSum);else go2(trie[x][i],pSum);
		pSum+=cnt[trie[x][i]];
//		chmin(l[x],go2(trie[x][i]));
	}
	return l[x];
}

void dfs(int x,int pSum=0)
{
	if(inS[x]) chmin(dp[x],sgt.query(pSum,pSum+1)+pSum+1);
	sgt.update(l[x],r[x],dp[x]-pSum);
	if(inS[x]) pSum++;
	for(int i=1;i<=26;i++)
	{
		if(trie[x][i]==-1) continue;
		chmin(dp[trie[x][i]],dp[x]+1);
		dfs(trie[x][i],pSum);
		pSum+=cnt[trie[x][i]];
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	memset(trie,-1,sizeof(trie));
	memset(inS,0,sizeof(inS));
	cin>>n;
	int x;
	char c;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&x,&c);
		trie[x][c-'a'+1]=i;
	}
	cin>>q;
	for(int i=0;i<q;i++)
	{
		scanf("%d",&x);
		dat[i]=x;
		trie[x][0]=END;
		lsh.push_back(x);
	}
	sort(all(lsh));
	for(int i=0;i<q;i++)
	{
		inS[dat[i]]=true;
	}
//	for(int i=0;i<=n;i++)
//	{
//		cout<<inS[i]<<' ';
//	}
//	cout<<endl;
	go(0);
//	cout<<"Now Printing cnt:";
//	for(int i=0;i<=n;i++)
//	{
//		cout<<cnt[i]<<' ';
//	}
//	cout<<endl;
	go2(0);
	for(int i=0;i<=n;i++)
	{
		if(l[i]==inf) continue;
		r[i]=l[i]+cnt[i];
	}
//	for(int i=0;i<=n;i++)
//	{
//		cout<<l[i]<<' '<<r[i]<<endl;
//	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	sgt.init(q);
	dfs(0);
	for(int i=0;i<q;i++)
	{
		printf("%d ",dp[dat[i]]);
	}
	return 0;
}