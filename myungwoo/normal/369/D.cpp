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

#define MAXN 3005

int N,K,P[MAXN],D[MAXN][MAXN],ans;
bool must[MAXN],never[MAXN];
queue <int> que;

int main()
{
	int i,j,k;
	scanf("%d%d",&N,&K);
	for (i=1;i<=N;i++) scanf("%d",P+i);
	bool sw=0;
	for (i=N;i;i--){
		if (P[i] == 100) sw = 1;
		must[i] = sw;
	}
	sw = 1;
	for (i=N;i;i--){
		if (P[i]) sw = 0;
		never[i] = sw;
	}
	for (i=1;i<=N+3;i++) for (j=1;j<=N+3;j++){
		D[i][j] = 1e9;
	}
	D[1][2] = 0; que.push(1), que.push(2);
	while (!que.empty()){
		int fr = que.front(); que.pop();
		int sc = que.front(); que.pop();
		ans++;
		if (fr >= N || sc > N || D[fr][sc] == K) continue;
		if (P[fr] && !must[sc] && D[fr][sc+1] == 1e9) que.push(fr), que.push(sc+1), D[fr][sc+1] = D[fr][sc]+1;
		if (P[fr] && !never[sc] && D[sc+1][sc+2] == 1e9) que.push(sc+1), que.push(sc+2), D[sc+1][sc+2] = D[fr][sc]+1;
		if (!never[sc] && P[fr] < 100){
			int a,b;
			a = sc, b = sc+1;
			if (D[a][b] < 1e9) continue;
			D[a][b] = D[fr][sc]+1;
			que.push(a), que.push(b);
		}
	}
	printf("%d\n",ans);
}