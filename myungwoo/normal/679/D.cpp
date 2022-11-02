#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

int N, M;
int w[401][401];
int last[401], K;
double P1[401], P2[401], mxp[402];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i=1;i<=N;i++) for (int j=1;j<=N;j++) w[i][j] = i == j ? 0 : 1e9;
	for (int i=1;i<=M;i++){
		int a, b; scanf("%d%d", &a, &b);
		w[a][b] = w[b][a] = 1;
	}
	for (int k=1;k<=N;k++) for (int i=1;i<=N;i++) for (int j=1;j<=N;j++)
		w[i][j] = min(w[i][j], w[i][k]+w[k][j]);
	double ans = 0;
	for (int i=1;i<=N;i++){
		double now = 0;
		for (int dist=0;dist<N;dist++){
			vector <int> arr;
			for (int j=1;j<=N;j++) if (w[i][j] == dist){
				arr.pb(j);
			}
			if (!sz(arr)) continue;
			for (int j=1;j<=N;j++) P1[j] = P2[j] = 0;
			for (int t: arr) P1[t] = 1. / sz(arr);
			vector <int> cand;
			for (int t: arr){
				int deg = 0;
				for (int j=1;j<=N;j++) if (w[t][j] == 1) deg++;
				for (int j=1;j<=N;j++) if (w[t][j] == 1) P2[j] += P1[t] / deg, cand.pb(j);
			}
			sort(all(cand)); cand.erase(unique(all(cand)), cand.end());
			double mx = 1. / sz(arr);
			for (int j=1;j<=N;j++){
				++K;
				for (int k: cand){
					if (last[w[j][k]] < K || last[w[j][k]] == K && mxp[w[j][k]] < P2[k])
						last[w[j][k]] = K, mxp[w[j][k]] = P2[k];
				}
				double now2 = 0;
				++K;
				for (int k: cand){
					if (last[w[j][k]] == K) continue;
					last[w[j][k]] = K;
					now2 += mxp[w[j][k]];
				}
				mx = max(mx, now2);
			}
			now += mx * sz(arr) / N;
		}
		ans = max(ans, now);
	}
	printf("%.9f\n", ans);
}