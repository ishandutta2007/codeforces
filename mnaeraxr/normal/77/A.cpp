#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

string name[7] = {"Dracul", "Troll", "Anka", "Hexadecimal", "Snowy", "Cleo", "Chapay"};

int num(string s){
	for (int i = 0; i < 7; ++i)
		if (s == name[i]) return i;
	return -1;
}

int mat[7][7];

int devil[7];
int val[3];
int tot[3];
int tmp[3];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; ++i){
		string u, l, v;
		cin >> u >> l >> v;
		mat[num(u)][num(v)] = 1;
	}

	cin >> val[0] >> val[1] >> val[2];

	int diff = oo, love = 0;

	for (int i = 0; i < 2187; ++i){
		tot[0] = tot[1] = tot[2] = 0;

		int v = i;
		for (int j = 0; j < 7; ++j){
			devil[j] = v % 3;
			tot[devil[j]]++;
			v /= 3;
		}

		if (!tot[0] || !tot[1] || !tot[2]) continue;
		for (int j = 0; j < 3; ++j) tmp[j] = val[j] / tot[j];

		sort(tmp, tmp + 3);

		if (tmp[2] - tmp[0] > diff) continue;

		int ll = 0;

		for (int j = 0; j < 7; ++j)
			for (int k = 0; k < 7; ++k)
				if (mat[j][k] && devil[j] == devil[k])
					++ll;

		if (tmp[2] - tmp[0] < diff){
			diff = tmp[2] - tmp[0];
			love = ll;
		}
		else if (tmp[2] - tmp[0] == diff)
			love = max(love, ll);
	}

	cout << diff << " " << love << endl;

	return 0;
}