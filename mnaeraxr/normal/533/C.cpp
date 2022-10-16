#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout<<#x<<"="<<x<<endl;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

void win(string s){
	cout << s << endl;
	exit(0);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int xp, yp, xv, yv;
	cin >> xp >> yp >> xv >> yv;
	if (xp + yp <= max(xv, yv)){
		win("Polycarp");
	}
	for (int i = 1; xv - i >= 0 && yv - i >= 0; ++i){
		if (abs(xp - (xv - i)) + abs(yp - (yv - i)) <= i)
			win("Polycarp");
	}
	win("Vasiliy");

	return 0;
}