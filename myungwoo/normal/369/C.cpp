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
typedef pair<int,int> pii;
typedef long long lld;

#define MAXN 100005

int N,D[MAXN];
bool chk[MAXN],V[MAXN];
vector <int> con[MAXN],ans;

void dfs(int n)
{
	V[n] = 1;
	int i,k,t;
	for (i=0;i<sz(con[n]);i+=2){
		k = con[n][i], t = con[n][i+1];
		if (V[k]) continue;
		if (t == 2) chk[k] = 1, D[n]++;
		dfs(k);
		D[n] += D[k];
	}
}

int main()
{
	int i,j,k,t;
	scanf("%d",&N);
	for (i=1;i<N;i++){
		scanf("%d%d%d",&j,&k,&t);
		con[j].pb(k), con[j].pb(t);
		con[k].pb(j), con[k].pb(t);
	}
	dfs(1);
	for (i=2;i<=N;i++) if (chk[i] && !D[i]) ans.pb(i);
	printf("%d\n",sz(ans));
	for (i=0;i<sz(ans);i++) printf("%d ",ans[i]); puts("");
}