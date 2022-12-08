#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector<int> G[100100];
int N,M,X[100100],Y[100100],D[100100];

bool chk(int x)
{
	for (int i=1;i<=N;i++) G[i].clear(), D[i] = 0;
	for (int i=0;i<=x;i++){
		G[X[i]].push_back(Y[i]);
		D[Y[i]]++;
	}

	queue<int> Q;
	for (int i=1;i<=N;i++) if (D[i] == 0){
		Q.push(i);
	}

	while (!Q.empty()){
		if (Q.size() > 1) return false;
		int x = Q.front(); Q.pop();
		for (int y : G[x]) if (--D[y] == 0) Q.push(y);
	}

	return true;
}

int main()
{
	scanf ("%d %d",&N,&M);
	for (int i=0;i<M;i++) scanf ("%d %d",&X[i],&Y[i]);

	int l = 0, r = M-1, a = M;
	while (l <= r){
		int m = (l + r) / 2;
		if (chk(m)){
			a = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	if (a == M) a = -1;
	else a++;
	printf ("%d\n",a);

	return 0;
}