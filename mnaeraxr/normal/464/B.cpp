#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200000 + 10;

int64 cube[8][3];
int explored = 0;

int64 sqr(int64 v){
	return v * v;
}

int64 dist(int i, int j){
	int64 answer = 0;
	for (int k = 0; k < 3; ++k)
		answer += sqr(cube[i][k] - cube[j][k]);
	return answer;
}

map<int64,int> freq;

bool check(){
	if (freq.size() > 3) return false;
	if (freq.size() < 3) return true;

	vector<int64> sides;

	for (auto s : freq)
		sides.push_back(s.first);

	sort(sides.begin(), sides.end());
	int64 a = sides[0], b = sides[1], c = sides[2];

	if (b != 2 * a || c != 3 * a)
		return false;

	if (freq[a] > 12) return false;
	if (freq[b] > 12) return false;
	if (freq[c] > 4) return false;

	return true;
}

void checkFull(){
	if (freq.size() != 3) return;

	vector<int64> sides;

	for (auto s : freq)
		sides.push_back(s.first);

	sort(sides.begin(), sides.end());
	int64 a = sides[0], b = sides[1], c = sides[2];

	if (b != 2 * a || c != 3 * a)
		return;

	if (freq[a] != 12) return;
	if (freq[b] != 12) return;
	if (freq[c] != 4) return;

	// Good

	cout << "YES" << endl;

	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 3; ++j)
			cout << cube[i][j] << " \n"[j + 1 == 3];

	exit(0);
}

void backtrack(int n){
	explored += 1;

	if (n == 8){
		checkFull();
		return;
	}

	if (!check())
		return;

	sort(cube[n], cube[n] + 3);

	do{
		for (int i = 0; i < n; ++i)
			freq[dist(i, n)]++;

		backtrack(n + 1);

		for (int i = 0; i < n; ++i){
			int64 d = dist(i, n);
			int f = --freq[d];

			if (f == 0)
				freq.erase(d);
		}

	} while(next_permutation(cube[n], cube[n] + 3));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 3; ++j)
			cin >> cube[i][j];

		sort(cube[i], cube[i] + 3);
	}

	backtrack(0);

	cout << "NO" << endl;

	return 0;
}

/*
887691 577079 -337
-193088 -342950 -683216
740176 -59645 -120545
592743 -30828 -283642
724594 652051 -193925
87788 -179853 -845476
665286 -133780 -846313
828383 -75309 -786168
 */