#include <stdio.h>
#include <vector>
using namespace std;

int N,K,S[200020]; bool chk[200020];
vector<int> G[200020];
long long ans;

void dfs(int x, int l)
{
	if (chk[x]) S[x] = 1;

	for (int y : G[x]) if (y != l){
		dfs(y,x); S[x] += S[y];
		int v = S[y];
		if (K * 2 - v < v) v = K * 2 - v;
		ans += v;
	}
}

int main()
{
	scanf ("%d %d",&N,&K);
	for (int i=0;i<K*2;i++){
		int x; scanf ("%d",&x);
		chk[x] = 1;
	}

	for (int i=1;i<N;i++){
		int x,y; scanf ("%d %d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}

	dfs(1,0);
	printf ("%lld\n",ans);

	return 0;
}