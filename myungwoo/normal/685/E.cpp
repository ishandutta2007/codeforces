#include <bits/stdc++.h>
using namespace std;

#define MAXM 200005
#define pb push_back

int N, M, Q;
int MT[1001][1001], X[1001], Y[1001];
int ans[MAXM];
vector <int> qidx[MAXM];

struct EDGE{
	int a, b;
} E[MAXM];

struct QUERY{
	int l, r, s, t, idx;
} QR[MAXM];

int main()
{
	scanf("%d%d%d", &N, &M, &Q);
	for (int i=1;i<=M;i++) scanf("%d%d", &E[i].a, &E[i].b);
	for (int i=1;i<=Q;i++){
		scanf("%d%d%d%d", &QR[i].l, &QR[i].r, &QR[i].s, &QR[i].t);
		qidx[QR[i].r].pb(i);
	}
	for (int i=1;i<=M;i++){
		int &a = E[i].a, &b = E[i].b;
		for (int j=1;j<=N;j++) X[j] = MT[a][j], Y[j] = MT[b][j];
		for (int j=1;j<=N;j++){
			// X -> MT[b]
			if (MT[b][j] < X[j]) MT[b][j] = X[j];
			// Y -> MT[a]
			if (MT[a][j] < Y[j]) MT[a][j] = Y[j];
		}
		MT[b][a] = MT[a][b] = i;
		for (int &q: qidx[i]){
			if (MT[QR[q].t][QR[q].s] >= QR[q].l) ans[q] = 1;
		}
	}
	for (int i=1;i<=Q;i++) puts(ans[i] ? "Yes" : "No");
}