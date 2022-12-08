#include <stdio.h>
#include <vector>
using namespace std;

int N,M,A[404][404],D[404][404],G[404];
double m[404],r[404]; int chk[404];
vector<int> u[404];

double prop(int l)
{
	for (int i=1;i<=N;i++) r[i] = 0;
	for (int &x : u[l]) for (int i=1;i<=N;i++) if (A[x][i]) r[i] += 1. / G[x];

	double mx = 1.;
	for (int d=0;d<N;d++) chk[d] = 0;
	for (int y=1;y<=N;y++){
		double sum = 0;
		for (int o=l-1;o<=l+1;o++) if (o >= 0){ 
			for (auto &i : u[o]){
				double &k = m[D[y][i]];
				if (chk[D[y][i]] != y){
					chk[D[y][i]] = y;
					k = r[i];
					sum += k;
				}
				else{
					if (k < r[i]){
						sum -= k;
						k = r[i];
						sum += k;
					}
				}
			}
		}
		if (mx < sum)
			mx = sum;
	}
	return mx;
}

int main()
{
	scanf ("%d %d",&N,&M);
	for (int i=1;i<=N;i++){
		for (int j=1;j<=N;j++) D[i][j] = 1000;
		D[i][i] = 0;
	}

	for (int i=0;i<M;i++){
		int x,y; scanf ("%d %d",&x,&y);
		A[x][y] = A[y][x] = D[x][y] = D[y][x] = 1;
		G[x]++; G[y]++;
	}

	for (int k=1;k<=N;k++) for (int i=1;i<=N;i++) for (int j=1;j<=N;j++) if (D[i][j] > D[i][k] + D[k][j]) D[i][j] = D[i][k] + D[k][j];

	double mx = 0;
	for (int x=1;x<=N;x++){
		for (int y=1;y<=N;y++) u[D[x][y]].push_back(y);
		double sum = 0;
		for (int d=0;d<N;d++) if (!u[d].empty()){
			double p = prop(d);
			sum += p / N;
		}
		for (int d=0;d<N;d++) u[d].clear();
		if (mx < sum)
			mx = sum;
	}
	printf ("%.12lf\n",mx);

	return 0;
}