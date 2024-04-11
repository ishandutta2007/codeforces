#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int> a;
	vector<int> b;
	int64 sa = 0, sb = 0;
	int last = 0;
	for (int i = 0; i < n; ++i){
		int v; cin >> v;
		if (v > 0){
			a.push_back(v);
			sa += v;
			last = 1;
		}
		else{
		 	b.push_back(-v);
		 	sb += abs(v);
		 	last = -1;
		}
	}

	if (sa != sb){
		if (sa > sb) cout << "first" << endl;
		else cout << "second" << endl;
	}
	else{
		int len = min(a.size(), b.size());
		for (int i = 0; i < len; ++i){
			if (a[i] != b[i]){
				if (a[i] > b[i])
					cout << "first" << endl;
				else
					cout << "second" << endl;
				return 0;
			}			
		}

		if (a.size() != b.size()){
			if (a.size() > b.size())
				cout << "first" << endl;
			else
				cout << "second" << endl;
			return 0;
		}

		if (last == 1) cout << "first" << endl;
		else cout << "second" << endl;
	}

	return 0;
}