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
#define TS 262144

int N,K,IDX,L,P,C,ans;
int num[MAXN],out[MAXN],dep[MAXN],mom[MAXN][17];
int tree[TS],ST=TS/2-1;
vector <int> con[MAXN];
priority_queue <pii> que;

void dfs(int n)
{
	int i,k;
	num[n] = ++IDX;
	for (i=sz(con[n]);i--;){
		k = con[n][i];
		if (!num[k]) mom[k][0] = n, dep[k] = dep[n]+1, dfs(k);
	}
	out[n] = IDX;
}

void _add(int n,int v)
{
	for (;n;n>>=1) tree[n] += v;
}

int get(int l,int r)
{
	int ret=0;
	for (;l<=r;l>>=1,r>>=1){
		if (l&1){
			ret += tree[l];
			l++;
		}
		if (!(r&1)){
			ret += tree[r];
			r--;
		}
	}
	return ret;
}

int get_edges()
{
	int ret=L;
	while (!que.empty() && que.top().sc < P) que.pop();
	int n = que.top().sc,i;
	for (i=17;i--;){
		int t = mom[n][i];
		if (t && get(ST+num[t],ST+out[t]) < C) n = t;
	}
	if (get(ST+num[n],ST+out[n]) < C) n = mom[n][0];
	if (n != 1) ret -= dep[n];
	return ret;
}

int main()
{
	int i,j,k;
	scanf("%d%d",&N,&K);
	for (i=1;i<N;i++){
		scanf("%d%d",&j,&k);
		con[j].pb(k); con[k].pb(j);
	}
	dfs(1);
	for (i=1;i<17;i++) for (j=1;j<=N;j++) mom[j][i] = mom[mom[j][i-1]][i-1];
	for (i=P=1;i<=N;i++){
		if (!get(ST+num[i],ST+out[i])){
			int n = i;
			for (j=17;j--;){
				int t = mom[n][j];
				if (t && !get(ST+num[t],ST+out[t])) n = t;
			}
			L += dep[i]-dep[n]+(n!=1);
		}
		_add(ST+num[i],1);
		que.push(mp(-dep[i],i)); C++;
		for (;;){
			int edges = get_edges();
			if (edges < K) break;
			int t = P++;
			_add(ST+num[t],-1); C--;
			if (get(ST+num[t],ST+out[t])) continue;
			int n = t;
			for (j=17;j--;){
				int p = mom[n][j];
				if (p && !get(ST+num[p],ST+out[p])) n = p;
			}
			L -= dep[t]-dep[n]+(n!=1);
		}
		if (ans < i-P+1) ans = i-P+1;
	}
	printf("%d\n",ans);
}