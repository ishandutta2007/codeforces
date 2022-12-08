#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int N,P[200020],D[200020];
vector<int> cyc;

int main()
{
	scanf ("%d",&N);
	for (int i=1;i<=N;i++) scanf ("%d",&P[i]), D[P[i]]++;

	queue<int> Q;
	for (int i=1;i<=N;i++) if (D[i] == 0){
		Q.push(i);
	}

	while (!Q.empty()){
		int x = Q.front(); Q.pop();
		if (--D[P[x]] == 0) Q.push(P[x]);
	}

	for (int i=1;i<=N;i++) if (D[i] == 1){
		int x = i;
		while (D[x] == 1){
			D[x] = 0;
			x = P[x];
		}
		cyc.push_back(i);
	}

	bool ed = 0;
	for (int i=0;i<cyc.size();i++) if (cyc[i] == P[cyc[i]]){
		printf ("%d\n",cyc.size()-1);
		for (int j=0;j<cyc.size();j++) if (i != j) P[cyc[j]] = cyc[i];
		ed = 1;
	}
	if (!ed){
		printf ("%d\n",cyc.size());
		for (int j=0;j<cyc.size();j++) P[cyc[j]] = cyc[0];
	}

	for (int i=1;i<=N;i++) printf ("%d ",P[i]); puts("");

	return 0;
}