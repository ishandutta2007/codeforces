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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int change = -1;

	int last = s[(int)s.length() - 1] - '0';

	for (int i = 0; i < (int)s.length() - 1; ++i){
		int cur = s[i] - '0';
		if (cur % 2 == 0){
			if (cur < last){
				s[i] = '0' + last;
				s[(int)s.length() - 1] = '0' + cur;
				cout << s << endl;
				return 0;
			}
			else{
				change = i;
			}
		}
	}
	if (change == -1) cout << -1 << endl;
	else{
		s[(int)s.length() - 1] = s[change];
		s[change] = '0' + last;
		cout << s << endl;
	}

	return 0;
}