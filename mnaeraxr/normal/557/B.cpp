#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	double w;
	cin >> n >> w;
	vector<double> V(2 * n);
	for (int i = 0; i < 2 * n; ++i)
		cin >> V[i];
	sort(V.begin(), V.end());
	double girl = V[0], boy = V[n];

	double lo = 0, hi = w;

	int MAGIC = 200;

	for (int i = 0; i < MAGIC; ++i){
		double mid = (lo + hi) / 2;
		double cgirl = mid / 3.0 / n;
		double cboy = 2 * cgirl;
		if (cgirl < girl && cboy < boy)
			lo = mid;
		else
			hi = mid;
	}

	cout.precision(7);
	cout << fixed << lo << endl;


	return 0;
}