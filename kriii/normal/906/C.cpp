#include <stdio.h>
#include <vector>
using namespace std;

int N,M,D[1<<22],V[1<<22],P[1<<22],c[22];

int main()
{
	scanf ("%d %d",&N,&M);
	for (int i=0;i<M;i++){
		int x,y; scanf ("%d %d",&x,&y);
		x--; y--;
		c[x] |= 1 << y;
		c[y] |= 1 << x;
	}
	if (M == N * (N - 1) / 2){
		puts("0");
		return 0;
	}

	for (int i=0;i<(1<<N);i++){
		if (i != (i & (-i))) D[i] = 0x7fffffff;
	}
	for (int i=1;i<(1<<N);i++) if (D[i] != 0x7fffffff){
		for (int j=0;j<N;j++) if (i & (1 << j)){
			int k = i | (c[j]);
			if (D[k] > D[i] + 1){
				D[k] = D[i] + 1;
				V[k] = i;
				P[k] = j+1;
			}
		}
	}

	vector<int> ans;
	int x = (1 << N) - 1;
	while (D[x]){
		ans.push_back(P[x]);
		x = V[x];
	}

	printf ("%d\n",ans.size());
	for (int i=(int)ans.size()-1;i>=0;i--) printf ("%d ",ans[i]);

	return 0;
}