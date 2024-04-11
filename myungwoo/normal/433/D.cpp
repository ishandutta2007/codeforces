#include <bits/stdc++.h>
using namespace std;

int N, M, Q;
int ans[1001];
int A[1001][1001], B[1001][1001];
int H[1001][1001], L[1001], R[1001];

struct {
	int t, y, x;
} P[1001];

void flip_updown()
{
	for (int i=1;i<N-i+1;i++){
		int j = N-i+1;
		for (int k=1;k<=M;k++) swap(A[i][k], A[j][k]);
	}
	for (int i=1;i<=Q;i++) P[i].y = N-P[i].y+1;
}

void rotate()
{
	for (int i=1;i<=N;i++) for (int j=1;j<=M;j++) B[i][j] = A[i][j];
	for (int i=1;i<=M;i++) for (int j=1;j<=N;j++) A[i][j] = B[j][i];
	swap(N, M);
	for (int i=1;i<=Q;i++) swap(P[i].y, P[i].x);
}

int proc2(int h, int t)
{
	int ret = 0;
	H[h][0] = H[h][M+1] = 0;
	stack <int> stk; stk.push(0);
	for (int i=1;i<=M;i++){
		while (!stk.empty() && H[h][stk.top()] >= H[h][i]) stk.pop();
		if (stk.empty()) L[i] = i;
		else L[i] = stk.top()+1;
		stk.push(i);
	}
	while (!stk.empty()) stk.pop(); stk.push(M+1);
	for (int i=M;i;i--){
		while (!stk.empty() && H[h][stk.top()] >= H[h][i]) stk.pop();
		if (stk.empty()) R[i] = i;
		else R[i] = stk.top()-1;
		stk.push(i);
	}
	for (int i=1;i<=M;i++)
		if (L[i] <= t && t <= R[i])
			ret = max(ret, (R[i]-L[i]+1) * H[h][i]);
	return ret;
}

void proc()
{
	for (int i=1;i<=N;i++) for (int j=1;j<=M;j++)
		H[i][j] = A[i][j] ? H[i-1][j]+1 : 0;
	for (int q=1;q<=Q;q++){
		auto &t = P[q];
		int y = t.y, x = t.x;
		if (t.t == 1){
			A[y][x] ^= 1;
			for (int i=y;i<=N;i++) H[i][x] = A[i][x] ? H[i-1][x]+1 : 0;
		}else{
			ans[q] = max(ans[q], proc2(y, x));
		}
	}
	// Rollback
	for (int q=1;q<=Q;q++){
		auto &t = P[q];
		if (t.t == 1) A[t.y][t.x] ^= 1;
	}
}

int main()
{
	scanf("%d%d%d", &N, &M, &Q);
	for (int i=1;i<=N;i++) for (int j=1;j<=M;j++) scanf("%d", A[i]+j);
	for (int i=1;i<=Q;i++) scanf("%d%d%d", &P[i].t, &P[i].y, &P[i].x);
	proc();
	flip_updown(); proc();
	rotate(); proc();
	flip_updown(); proc();
	for (int i=1;i<=Q;i++) if (P[i].t == 2) printf("%d\n", ans[i]);
}