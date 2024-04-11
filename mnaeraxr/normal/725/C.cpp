#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int pos[26];

char A[2][20];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	memset(pos, -1, sizeof pos);

	string s; cin >> s;

	int b = -1, e = -1;

	for (int i = 0; i < 27; ++i){
		int c = s[i] - 'A';

		if (pos[c] == -1) pos[c] = i;
		else{
			b = pos[c];
			e = i;
			break;
		}
	}

	if (b + 1 == e){
		cout << "Impossible" << endl;
		return 0;
	}

	int sz = e - b - 1;

	int point = 13 - (sz & 1 ? (sz + 1) / 2 : sz / 2 + 1);

	A[0][point] = s[b];
	int x = 0, y = point + 1;

	for (int j = b + 1; j < e; ++j){
		if (y == 13){
			y = 12;
			x = 1;
		}

		A[x][y] = s[j];
		if (x == 0) y++;
		else y--;
	}

	x = 0, y = point - 1;
	for (int i = b - 1; i >= 0; --i){
		if (y == -1){
			y = 0;
			x = 1;
		}

		A[x][y] = s[i];
		if (x == 0) y--;
		else y++;
	}

	for (int i = 26; i > e; --i){
		if (y == -1){
			y = 0;
			x = 1;
		}

		A[x][y] = s[i];
		if (x == 0) y--;
		else y++;
	}

	for (int i = 0; i < 2; ++i){
		for (int j = 0; j < 13; ++j)
			cout << A[i][j];
		cout << endl;
	}


	return 0;
}