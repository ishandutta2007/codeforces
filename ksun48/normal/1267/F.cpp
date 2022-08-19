#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M; cin >> N >> M;
	int KA, KB; cin >> KA >> KB;
	vector<int> pa(KA);
	for (int i = 0; i < KA; i++) {
		cin >> pa[i]; pa[i] --;
	}
	vector<int> pb(KB);
	for (int i = 0; i < KB; i++) {
		cin >> pb[i]; pb[i] --;
	}

	if (int(pa.size()) > M-1 || int(pb.size()) > N-1) {
		cout << "No" << '\n';
		exit(0);
	}
	cout << "Yes" << '\n';
	while (int(pa.size()) < M - 1) {
		pa.push_back(0);
	}
	while (int(pb.size()) < N - 1) {
		pb.push_back(N);
	}

	vector<int> cnt(N+M);
	for (int i : pa) cnt[i]++;
	for (int i : pb) cnt[i]++;

	priority_queue<int, vector<int>, greater<int>> leaves;
	for (int i = 0; i < N+M; i++) {
		if (cnt[i] == 0) leaves.push(i);
	}
	int ia = 0;
	int ib = 0;
	for (int z = 0; z < N+M-2; z++) {
		int cur = leaves.top(); leaves.pop();
		int nxt;
		if (cur < N) {
			nxt = pb[ib++];
		} else {
			nxt = pa[ia++];
		}
		cout << cur+1 << ' ' << nxt+1 << '\n';
		if ((--cnt[nxt]) == 0) {
			leaves.push(nxt);
		}
	}

	int va = leaves.top(); leaves.pop();
	int vb = leaves.top(); leaves.pop();
	cout << va+1 << ' ' << vb+1 << '\n';

	return 0;
}