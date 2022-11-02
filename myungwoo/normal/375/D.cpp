#include <vector>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

#pragma comment(linker,"/STACK:33554432")

#define eps 1e-9
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define same(a,b) (fabs((a)-(b))<eps)
#define set(arr,with) memset(arr,with,sizeof(arr))
#define add(target,value,mod) target = (target+value)%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef long long lld;
typedef pair<int,int> pii;
typedef pair<lld,int> pli;
typedef pair<int,lld> pil;
typedef pair<lld,lld> pll;

#define MAXN 100005

int N,M,C[MAXN],S[MAXN],ans[MAXN];
int bit[MAXN],cnt[MAXN];
vector <int> grp[MAXN],con[MAXN];
vector <pii> Q[MAXN];

void _dfs(int n,int p)
{
	int i,k;
	S[n]++;
	for (i=0;i<sz(grp[n]);i++){
		k = grp[n][i];
		if (p != k) con[n].pb(k), _dfs(k,n), S[n] += S[k];
	}
}

void _add(int n,int v)
{ for (n=1e5-n+2;n<MAXN;n+=(n&-n)) bit[n] += v; }
int _get(int n)
{
	int ret=0;
	for (n=1e5-n+2;n;n-=(n&-n)) ret += bit[n];
	return ret;
}

void _upd(int n,int v)
{
	_add(cnt[n],-1);
	cnt[n] += v;
	_add(cnt[n],1);
}

void clear(int n)
{
	_upd(C[n],-1);
	for (int i=0;i<sz(con[n]);i++) clear(con[n][i]);
}
void reg(int n)
{
	_upd(C[n],1);
	for (int i=0;i<sz(con[n]);i++) reg(con[n][i]);
}

void dfs(int n)
{
	int i,k;
	int mx=0,tar=0;
	for (i=0;i<sz(con[n]);i++){
		k = con[n][i];
		if (mx < S[k]) mx = S[k], tar = k;
	}
	for (i=0;i<sz(con[n]);i++){
		k = con[n][i];
		if (tar != k) dfs(k), clear(k);
	}
	if (tar) dfs(tar);
	_upd(C[n],1);
	for (i=0;i<sz(con[n]);i++){
		k = con[n][i];
		if (tar != k) reg(k);
	}
	for (i=0;i<sz(Q[n]);i++){
		ans[Q[n][i].fr] = _get(Q[n][i].sc);
	}
}

int main()
{
	int i,j,k;
	scanf("%d%d",&N,&M);
	for (i=1;i<=N;i++) scanf("%d",C+i);
	for (i=1;i<N;i++){
		scanf("%d%d",&j,&k);
		grp[j].pb(k), grp[k].pb(j);
	}
	for (i=1;i<=M;i++){
		scanf("%d%d",&j,&k);
		Q[j].pb(mp(i,k));
	}
	_dfs(1,0);
	dfs(1);
	for (i=1;i<=M;i++) printf("%d\n",ans[i]);
}