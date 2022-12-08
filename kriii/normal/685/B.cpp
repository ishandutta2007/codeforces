#include <stdio.h>
#include <vector>
using namespace std;

vector<int> T[300300];
int N,Q,P[300300],S[300300],C[300300];

void dfs(int x)
{
	S[x] = 1;
	vector<int> c;
	for (int y : T[x]){
		dfs(y);
		S[x] += S[y];
		c.push_back(C[y]);
	}

	for (int i=0;i<T[x].size();i++){
		int y = T[x][i];
		if (S[y] * 2 >= S[x]){
			y = C[y];
			while (S[y] * 2 < S[x]) y = P[y];
			C[x] = y;
			return;
		}
	}
	C[x] = x;
}

int main()
{
	scanf ("%d %d",&N,&Q);
	for (int i=2;i<=N;i++) scanf ("%d",&P[i]), T[P[i]].push_back(i);
	dfs(1);

	for (int i=0;i<Q;i++){
		int x; scanf ("%d",&x);
		printf ("%d\n",C[x]);
	}

	return 0;
}