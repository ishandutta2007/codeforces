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
const int MAXN = (int)5e5 + 10;

bool isVowel(char c){
	return c == 'I' || c == 'E' || c == 'A' || c == 'O' || c == 'U' || c == 'Y';
}
int km[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s; cin >> s;
	for (int i = 0; i < (int)s.length(); ++i){
		if (isVowel(s[i])){
			int r = i, l = (int)s.length() - r - 1;
			if (r > l) swap(r, l);
			km[1]++;
			km[r+2]--;
			km[l+2]--;
		}
	}

	long double ans = 0;
	long double ONE = 1.0;
	for (int64 i = 1, cur = 0, k = 0; i <= (int)s.length(); ++i){
		k += km[i];
		cur += k;
		ans += ONE * cur / i;
	}

	cout.precision(8);
	cout << fixed << ans << endl;

	return 0;
}