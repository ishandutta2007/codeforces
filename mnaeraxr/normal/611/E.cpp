#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200000 + 10;

int order[7] = {1, 2, 4, 1 + 2, 1 + 4, 2 + 4, 1 + 2 + 4};
int musketeer[3];
int strength[7];
int criminal[maxn];

int min_time(int a, int b, int c, int ab, int ac, int bc, int abc){
	return ab + ac + bc + max({a - bc, b - ac, c - ab, 0}) + abc;
}

bool solve(int t, int n){

	int va, vb, vc, vab, vac, vbc, vabc;
	va = vb = vc = vab = vac = vbc = vabc = 0;
	int sa = strength[0], sb = strength[1], sc = strength[2];

	for (int i = 0; i < n; ++i){
		int c = criminal[i];

		if (sa >= c && min_time(va + 1, vb, vc, vab, vac, vbc, vabc) <= t){
			va++;
		}
		else if (sb >= c && min_time(va, vb + 1, vc, vab, vac, vbc, vabc) <= t){
			vb++;
		}
		else if (sc >= c && min_time(va, vb, vc + 1, vab, vac, vbc, vabc) <= t){
			vc++;
		}
		else if (sa + sb >= c && min_time(va, vb, vc, vab + 1, vac, vbc, vabc) <= t){
			vab++;
		}
		else if (sa + sc >= c && min_time(va, vb, vc, vab, vac + 1, vbc, vabc) <= t){
			vac++;
		}
		else if (sc + sb >= c && min_time(va, vb, vc, vab, vac, vbc + 1, vabc) <= t){
			vbc++;
		}
		else if (min_time(va, vb, vc, vab, vac, vbc, vabc+1) <= t){
			vabc++;
		}
		else
			return false;
	}

	return true;
}

/*
30
34938093 71279712 25853338
29827587 21741565 52179990 30235076 83272806 10815432 98887688 94542207 99870240 97586453 21739186 30460781 75347784 50711354 12162179 74306503 97398492 88466481 52489587 67579359 53177356 75077523 86044366 14405531 73916272 78242091 49321886 41937821 89258359 51438752
 */

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	int sum = 0;
	for (int i = 0; i < 3; ++i){
		cin >> musketeer[i];
		sum += musketeer[i];
	}

	sort(musketeer, musketeer + 3);

	for (int i = 0; i < n; ++i)
		cin >> criminal[i];

	sort(criminal, criminal + n);
	reverse(criminal, criminal + n);

	if (criminal[0] > sum){
		cout << -1 << endl;
		exit(0);
	}

	for (int i = 0; i < 7; ++i){
		for (int j = 0; j < 3; ++j){
			if (order[i] >> j & 1)
				strength[i] += musketeer[j];
		}
	}

	int lo = 0, hi = n;
	while (lo + 1 < hi){
		int mid = (lo + hi) / 2;
		if (solve(mid, n)) hi = mid;
		else lo = mid;
	}

	cout << hi << endl;

	return 0;
}