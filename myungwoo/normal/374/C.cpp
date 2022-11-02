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

int yy[]={-1,0,1,0},xx[]={0,1,0,-1};
int N,M,K,ans;
int in[1001][1001],D[1001][1001];
char A[1001][1002],nxt[128];
queue <int> que;
vector <pii> order;

int main()
{
	int i,j,k;
	bool sw=0;
	nxt['D'] = 'I'; nxt['I'] = 'M'; nxt['M'] = 'A'; nxt['A'] = 'D';
	scanf("%d%d",&N,&M);
	for (i=1;i<=N;i++) scanf("%s",A[i]+1);
	for (i=1;i<=N;i++) for (j=1;j<=M;j++){
		D[i][j] = -1;
		for (k=0;k<4;k++){
			int y=i+yy[k],x=j+xx[k];
			if (y < 1 || x < 1 || y > N || x > M) continue;
			if (nxt[A[i][j]] == A[y][x]) in[y][x]++;
		}
	}
	for (i=1;i<=N;i++) for (j=1;j<=M;j++) if (!in[i][j]) que.push(i), que.push(j);
	while (!que.empty()){
		int y = que.front(); que.pop();
		int x = que.front(); que.pop();
		order.pb(mp(y,x));
		for (i=0;i<4;i++){
			int ny=y+yy[i],nx=x+xx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > M || nxt[A[y][x]] != A[ny][nx]) continue;
			if (!--in[ny][nx]) que.push(ny), que.push(nx);
		}
	}
	for (i=0;i<sz(order);i++){
		int y = order[i].fr, x = order[i].sc;
		if (A[y][x] == 'D') put_max(D[y][x],0);
		if (D[y][x] < 0) continue;
		if (A[y][x] == 'A') D[y][x]++;
		for (j=0;j<4;j++){
			int ny=y+yy[j],nx=x+xx[j];
			if (ny < 1 || nx < 1 || ny > N || nx > M || nxt[A[y][x]] != A[ny][nx]) continue;
			put_max(D[ny][nx],D[y][x]);
		}
		put_max(ans,D[y][x]);
	}
	if (sz(order) != N*M){ puts("Poor Inna!"); return 0; }
	if (ans) printf("%d\n",ans);
	else puts("Poor Dima!");
}