#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef pair<int, int> pii;

int N, M, P;
int A[302][302], B[302];
int D[302][302];
priority_queue <pii> Q[302];
queue <int> QQ[302];

struct Z{
	int y, x;
};
vector <Z> pos[90001];

inline int dist(int x, int y, int p, int q)
{ return abs(x-p) + abs(y-q); }

int main()
{
	scanf("%d%d%d", &N, &M, &P);
	for (int i=1;i<=N;i++) for (int j=1;j<=M;j++) scanf("%d", A[i]+j);
	for (int i=1;i<=N;i++) for (int j=1;j<=M;j++){
		pos[A[i][j]].pb({i, j});
		if (A[i][j] == 1) D[i][j] = dist(1, 1, i, j);
	}
	for (int i=2;i<=P;i++){
		for (int j=1;j<=M;j++){
			B[j] = 1e9;
			while (!Q[j].empty()) Q[j].pop();
			while (!QQ[j].empty()) QQ[j].pop();
		}
		for (Z &z: pos[i-1]){
			Q[z.x].push({-(D[z.y][z.x]+z.y), z.y});
			QQ[z.x].push(z.y);
		}
		for (Z &z: pos[i]){
			int &v = D[z.y][z.x];
			v = 1e9;
			for (int j=1;j<=M;j++){
				while (!Q[j].empty() && Q[j].top().second < z.y) Q[j].pop();
				while (!QQ[j].empty() && QQ[j].front() < z.y){
					int y = QQ[j].front(), x = j;
					QQ[j].pop();
					B[j] = min(B[j], D[y][x]-y);
				}
				v = min(v, B[j]+z.y + abs(z.x-j));
				if (!Q[j].empty()) v = min(v, -Q[j].top().first-z.y + abs(z.x-j));
			}
		}
	}
	int ans = 1e9;
	for (int i=1;i<=N;i++) for (int j=1;j<=M;j++) if (A[i][j] == P) ans = min(ans, D[i][j]);
	printf("%d\n", ans);
}