#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define mp make_pair
#define all(v) (v).begin(), (v).end()
typedef pair<int, int> pii;
typedef long long lld;

int N, M;
struct Z{
	int x, y, idx;
} A[MAXN], B[MAXN];

double intersect(const Z &a, const Z &b)
{
	return (double)((lld)a.x*b.x*(a.y-b.y)) / ((lld)a.y*b.y*(b.x-a.x));
}

int main()
{
	scanf("%d", &N);
	for (int i=1;i<=N;i++) scanf("%d%d", &A[i].x, &A[i].y), A[i].idx = i;
	sort(A+1, A+N+1, [](const Z &a, const Z &b){
		return a.x != b.x ? a.x > b.x : a.y > b.y;
	});
	B[++M] = A[1];
	for (int i=2;i<=N;i++) if (A[i].x != A[i-1].x) B[++M] = A[i];
	vector <int> stk(M+1, 0);
	vector <double> dstk(M+1, 0);
	int scnt = 0;
	stk[++scnt] = 1; dstk[scnt] = 1e18;
	for (int i=2;i<=M;i++){
		while (scnt > 1){
			double p = dstk[scnt], q = intersect(B[stk[scnt-1]], B[i]);
			if (p < q-1e-9) scnt--;
			else break;
		}
		stk[++scnt] = i; dstk[scnt] = intersect(B[stk[scnt-1]], B[i]);
	}
	while (scnt && dstk[scnt] < 1e-9) scnt--;
	vector <int> ans;
	set <pii> S;
	for (int i=1;i<=scnt;i++) S.insert(mp(B[stk[i]].x, B[stk[i]].y));
	for (int i=1;i<=N;i++) if (S.count(mp(A[i].x, A[i].y))) ans.push_back(A[i].idx);
	sort(all(ans));
	for (int v: ans) printf("%d ", v); puts("");
}