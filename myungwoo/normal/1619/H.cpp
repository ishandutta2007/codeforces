#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int N, Q, K;
int P[MAXN], R[MAXN], G[MAXN];

void precalc()
{
	for (int i=1;i<=N;i++) if (!G[i]){
		int b = i;
		for (int j=0;j<K;j++) b = P[b];
		for (int j=i;!G[j];j=P[j],b=P[b]) G[j] = b;
	}
}

int get(int n, int step)
{
	while (step >= K){
		n = G[n];
		step -= K;
	}
	while (step--){
		n = P[n];
	}
	return n;
}

void refresh(int n)
{
	int m = n;
	for (int i=0;i<K;i++) m = P[m];
	G[n] = m;
	for (int i=0;i<K;i++){
		n = R[n]; m = R[m];
		G[n] = m;
	}
}

void do_swap(int a, int b)
{
	swap(P[a], P[b]);
	swap(R[P[a]], R[P[b]]);
	refresh(a); refresh(b);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q; K = sqrt(N);
	for (int i=1;i<=N;i++){
		cin >> P[i];
		R[P[i]] = i;
	}
	precalc();
	while (Q--){
		int t, a, b;
		cin >> t >> a >> b;
		if (t == 2) cout << get(a, b) << '\n';
		else do_swap(a, b);
	}
}