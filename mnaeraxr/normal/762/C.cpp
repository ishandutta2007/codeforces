#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

const int64 oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

vector<vi> build(string &a){
	int n = a.length();
	vector<vi> go(a.length() + 1, vi(26, n));

	for (int i = n - 1; i >= 0; --i){
		go[i] = go[i + 1];
		go[i][a[i] - 'a'] = i;
	}

	return go;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

	auto GO = build(a);
	reverse(a.begin(), a.end());
	auto RGO = build(a);

	int na = (int)a.length(), nb = (int)b.length();

	vector<int> pos(nb, -1);

	int answer = 0;
	int B, E;

	for (int i = nb - 1, p = 0; i >= 0; --i){
		p = RGO[p][b[i] - 'a'];
		pos[i] = na - p - 1;

		if (p == na) break;
		else{
			B = 0;
			E = i;
			answer = nb - i;
		}

		p++;
	}

	for (int i = 0, p = 0; i < nb; ++i){
		p = GO[p][b[i] - 'a'];

		if (p == na) break;

		int l = -1, h = nb;

		while (l + 1 < h){
			int m = (l + h) >> 1;
			if (pos[m] > p) h = m;
			else l = m;
		}

		int curans = i + 1 + nb - h;

		if (curans >= nb){
			B = 0, E = 0;
			answer = 1;
			break;
		}

		if (curans > answer){
			answer = curans;
			B = i + 1;
			E = h;
		}
		p++;
	}

//	cout << answer << endl;

	if (answer == 0)
		cout << "-" << endl;
	else{
		cout << b.substr(0, B);
		cout << b.substr(E);
		cout << endl;
	}

	return 0;
}