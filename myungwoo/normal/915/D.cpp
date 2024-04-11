#include <bits/stdc++.h>
using namespace std;

#define MAXM 100005
#define pb push_back

int N, M;
vector <int> con[501];

bool test(int idx)
{
	vector <int> in(N+1, 0);
	for (int i=1;i<=N;i++) for (int t: con[i]) in[t]++;
	in[idx]--;
	queue <int> que;
	for (int i=1;i<=N;i++) if (in[i] <= 0) que.push(i);
	int cnt = 0;
	while (!que.empty()){
		int q = que.front(); que.pop(); cnt++;
		for (int t: con[q]) if (!--in[t]) que.push(t);
	}
	return cnt == N;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i=1;i<=M;i++){
		int a, b; cin >> a >> b;
		con[a].pb(b);
	}
	for (int i=1;i<=N;i++) if (test(i)){ puts("YES"); return 0; }
	puts("NO");
}