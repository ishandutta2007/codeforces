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

#pragma comment(linker,"/STACK:67108864")

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
typedef pair<int,int> pii;
typedef long long lld;

#define MAXN 500005
#define TS 1048576

const int ST=TS/2-1;
int N,Q,K,mom[MAXN],idx[MAXN],out[MAXN];
int range[TS],tree[TS];
vector <int> con[MAXN];
queue <int> que;

void dfs(int n)
{
	int i,k;
	idx[n] = ++K;
	for (i=sz(con[n]);i--;){
		k = con[n][i];
		if (!mom[k]) mom[k] = n, dfs(k);
	}
	out[n] = K;
}

int main()
{
	int i,j,k,id,t,v,l,r,n,fill,empty;
	scanf("%d",&N);
	for (i=1;i<N;i++){
		scanf("%d%d",&j,&k);
		con[j].pb(k), con[k].pb(j);
	}
	mom[1] = 1; dfs(1);
	scanf("%d",&Q);
	for (id=1;id<=Q;id++){
		scanf("%d%d",&t,&v);
		if (t == 1){
			for (l=ST+idx[v],r=ST+out[v];l<=r;l>>=1,r>>=1){
				if (l&1){
					range[l] = id;
					l++;
				}
				if (!(r&1)){
					range[r] = id;
					r--;
				}
			}
		}else if (t == 2){
			for (n=ST+idx[v];n;n>>=1) tree[n] = id;
		}else{
			fill = empty = 0;
			for (n=ST+idx[v];n;n>>=1) put_max(fill,range[n]);
			for (l=ST+idx[v],r=ST+out[v];l<=r;l>>=1,r>>=1){
				if (l&1){
					put_max(empty,tree[l]);
					l++;
				}
				if (!(r&1)){
					put_max(empty,tree[r]);
					r--;
				}
			}
			puts(empty>=fill?"0":"1");
		}
	}
}