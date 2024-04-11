#include <bits/stdc++.h>

using namespace std;

set<int> diagonal;
vector<int> hor, ver;

int ask(int x, int y){
	cout << 0 << " " << x << " " << y << endl;
	int v; cin >> v;
	return v;
}

void find_points(int lo, int hi){
	if (hi < lo) return;
	int mid = (lo + hi) / 2;

	int d = ask( mid, mid );

	if (d == 0){
		diagonal.insert( mid );
		d++;
	}

	find_points(lo, mid - d);
	find_points(mid + d, hi);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	find_points(-100000000, 100000000);

	int foo = 0;
	while (diagonal.count(foo))
		foo++;

	for (auto p : diagonal){
		if (ask(p, foo) == 0)
			hor.push_back(p);

		if (ask(foo, p) == 0)
			ver.push_back(p);
	}

	cout << 1 << " " << hor.size() << " " << ver.size() << endl;

	for (int i = 0; i < (int)hor.size(); ++i)
		cout << hor[i] << " \n"[i + 1 == (int)hor.size()];

	for (int i = 0; i < (int)ver.size(); ++i)
		cout << ver[i] << " \n"[i + 1 == (int)ver.size()];

	cout.flush();

	return 0;
}