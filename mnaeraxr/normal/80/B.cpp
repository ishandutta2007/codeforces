#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int main()
{
	int h, m;
	scanf("%d:%d", &h, &m);

	h %= 12;

//	if (h % 12 == 0 && m == 0){
//		cout << "0 0" << endl;
//		exit(0);
//	}

	double mm = 6.0 * m;
	double hh = 360.0 * (1.0 * h / 12 + 1.0 * m / 60 / 12);

	cout.precision(17);
	cout << fixed << hh << " " << mm << endl;

	return 0;
}