#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int N;
	cin >> N;
	int n = (1 << N);
	double prob[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> prob[i][j];
			prob[i][j] /= 100.0;
		}
	}
	double best[N+1][n][n];
	double pwin[N+1][n][n];
	for(int i = 0; i <= N; i++){
		if(i == 0){
			for(int j = 0; j < n; j++){
				for(int k = 0; k < n; k++){
					best[i][j][k] = 0.0;
					pwin[i][j][k] = 0.0;
				}
				pwin[i][j][j] = 1.0;
			}
			continue;
		}
		for(int j = 0; j < n; j += (1<<i)){
			for(int k = 0; k < n; k++){
				best[i][j][k] = 0.0;
				pwin[i][j][k] = 0.0;
			}
		}
		for(int j = 0; j < n; j += (1<<i)){
			for(int t1 = j; t1 < j + (1<<(i-1)); t1++){
				for(int t2 = j+(1<<i-1); t2 < j + 2*(1<<(i-1)); t2++){
					pwin[i][j][t1] += prob[t1][t2]*pwin[i-1][j][t1]*pwin[i-1][j+(1<<(i-1))][t2];
					pwin[i][j][t2] += prob[t2][t1]*pwin[i-1][j][t1]*pwin[i-1][j+(1<<(i-1))][t2];
				}
			}
		}
		for(int j = 0; j < n; j += (1<<i)){
			for(int t1 = j; t1 < j + (1<<(i-1)); t1++){
				for(int t2 = j+(1<<i-1); t2 < j + 2*(1<<(i-1)); t2++){
					double score1 = pwin[i][j][t1];
					for(int z = 1; z < i; z++){
						score1 *= 2.0;
					}
					best[i][j][t1] = max(best[i][j][t1],
						best[i-1][j][t1] + score1 + best[i-1][j+(1<<(i-1))][t2]);
					double score2 = pwin[i][j][t2];
					for(int z = 1; z < i; z++){
						score2 *= 2.0;
					}
					best[i][j][t2] = max(best[i][j][t2],
						best[i-1][j][t1] + score2 + best[i-1][j+(1<<(i-1))][t2]);				
				}
			}
		}
	}
	double ans = 0;
	for(int i = 0; i < n; i++){
		ans = max(ans, best[N][0][i]);
	}
	//cout << setprecision(15) << ans << endl;
	printf("%.15lf\n", ans);
}