#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

map<int,int> M;
set<int> S;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i){
		int a, b;
		cin >> a >> b;
		M[a] = b;
		S.insert(b);
	}

	int s1 = 0, s2 = -1;
	for (auto v : M){
		if (!S.count(v.first)){
			s2 = v.first;
			break;
		}
	}

	while (s2 != 0){
		cout << s2 << " ";
		int t = s2;
		s2 = M[s1];
		s1 = t;
	}
	cout << endl;


	return 0;
}