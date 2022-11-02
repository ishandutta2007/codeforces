#include <bits/stdc++.h>

using namespace std;

#define INF 2147483647
#define MOD 1000000007
#define MAX 100000

typedef long long ll;
typedef pair<int, int> pii;

vector<string> strs;

int toint(const string &s)
{
	stringstream ss(s);
	int num;
	ss >> num;
	return num;
}

int n;

vector<bool> sign;
vector<int> solution;

int main()
{
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
#else
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#endif // LOCAL

    string s;
    while (cin >> s, cin) {
		strs.push_back(s);
    }

    n = toint(strs.back());
    int nplus = 1, nmin = 0;
    sign.push_back(true);
    for (int i = 1; i + 2 < (int) strs.size(); i += 2) {
		string ss = strs[i];
//		cerr << ss << " ";
		if (ss == "+") nplus++, sign.push_back(true);
		else if (ss == "-") nmin++, sign.push_back(false);
    }

//	cerr << nplus << " " << nmin << endl;

	int minsum = nplus - n * nmin;
	int maxsum = n * nplus - nmin;

//	cerr << minsum << " " << maxsum << endl;

	if (minsum <= n && n <= maxsum) {
		cout << "Possible" << endl;
		// find a solution

		vector<int> solplus, solmin;
		int sumPlus = min(n * nplus, n * nmin + n);
		int sumMin = sumPlus - n;

		// cerr << sumPlus1 << " " << sumMin1 << endl;
		// cerr << sumPlus2 << " " << sumMin2 << endl;

		for (int i = nplus; i--; ) {
			// after this one we need to fill in i +-gaps
			int add = min(n, max(1, sumPlus - i));
			sumPlus -= add;
			solplus.push_back(add);
		}
		for (int i = nmin; i--; ) {
			int add = min(n, max(1, sumMin - i));
			sumMin -= add;
			solmin.push_back(add);
		}
		assert(sumPlus == 0);
		assert(sumMin == 0);

		for (int i = 0; i < (int) sign.size(); i++) {
			if (sign[i]) {
				solution.push_back(solplus.back());
				solplus.pop_back();
			} else {
				solution.push_back(solmin.back());
				solmin.pop_back();
			}
		}

		for (int i = 0; i < (int) sign.size(); i++) {
			if (i > 0) {
				cout << (sign[i] ? " + " : " - ");
			}
			cout << solution[i];
		}
		cout << " = " << n << endl;
	} else {
		cout << "Impossible" << endl;
	}
    return 0;
}