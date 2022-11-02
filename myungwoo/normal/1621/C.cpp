#include <bits/stdc++.h>
using namespace std;

int ask(int x)
{
	cout << "? " << x << '\n';
	cout.flush();
	int res;
	cin >> res;
	return res;
}

void solve()
{
	int N;
	cin >> N;
	vector<vector<int>> cycles;
	set<int> left;
	for (int i=1;i<=N;i++) left.insert(i);
	while (!left.empty()){
		int pos = *left.begin();
		int init = ask(pos);
		vector<int> comp = {init};
		for (;;){
			int v = ask(pos);
			left.erase(v);
			if (init == v) break;
			comp.push_back(v);
		}
		cycles.push_back(move(comp));
	}
	vector<int> perm(N+1);
	for (auto& comp: cycles){
		for (int i=1;i<comp.size();i++) perm[comp[i-1]] = comp[i];
		perm[comp.back()] = comp[0];
	}
	cout << '!';
	for (int i=1;i<=N;i++) cout << ' ' << perm[i];
	cout << '\n';
	cout.flush();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	for (cin >> T;T--;) solve();
}