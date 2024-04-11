#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const double EPS = 1e-9;
const int oo = 0x3f3f3f3;
const int MAXN = (int)1e5 + 10;

void bad(){
	cout << -1 << endl;
	exit(0);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, h, d;
	cin >> n >> d >> h;

	if (d > 2 * h) bad();

	if (d == h){

		if (d == 1 && n > 2) bad();

		for (int i = 2; i <= d + 1; ++i)
			cout << i - 1 << " " << i << endl;

		for (int i = d + 2; i <= n; ++i)
			cout << 2 << " " << i << endl;

		exit(0);
	}

	int pnt = 1;

	for (int i = 2; i <= h + 1; ++i){
		pnt++;
		cout << pnt - 1 << " " << pnt << endl;
	}

	for (int i = 0; i < d - h; ++i){
		pnt++;
		if (!i) cout << 1 << " " << pnt << endl;
		else cout << pnt - 1 << " " << pnt << endl;
	}

	while (pnt < n){
		pnt++;
		cout << 1 << " " << pnt << endl;
	}



	return 0;
}