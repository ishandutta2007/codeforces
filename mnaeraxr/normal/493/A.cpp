#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	cin >> a >> b;
	int q; cin >> q;

    map<int,int> M;
	for (int i = 0; i < q; ++i){
		int t, n;
		string s, c;
		cin >> t >> s >> n >> c;
		if (s == "a") n = -n;
		int val = ((c == "y") ? 1 : 2);
		M[n] += val;
		if (M[n] >= 2){
			M[n] = -100000;
			if (s == "h") cout << a << " ";
			else cout << b << " ";
			cout << abs(n) << " " << t << endl;
		}
	}

	return 0;
}