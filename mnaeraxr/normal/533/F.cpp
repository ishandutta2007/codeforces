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
const int MAXN = (int)2e5 + 10;

char A, B;

bool compare(char &a, char &b){
	return (a == A) == (b == B);
}

int  pi[MAXN];
bool ok[26][26][MAXN];
int last[MAXN];

void build_pi(string &s){
	pi[0] = -1, pi[1] = 0;
	for (int i = 2, k = 0; i <= SZ(s); ++i){
		while (k >= 0 && !compare(s[i - 1], s[k])) k = pi[k];
		pi[i] = ++k;
	}
}

void match(string &s, string &t, bool m[MAXN]){
	for (int i = 1, k = 0; i <= SZ(s); ++i){
		while (k >= 0 && !compare(s[i - 1], t[k])) k = pi[k];
		++k;
		if (k == SZ(t)){
			k = pi[k];
//			cout << A << " " << B << " " << i << endl;
			m[i] = true;
		}
	}
}

void build(string &s, string &t){
	for (int i = 0; i < 26; ++i){
		for (int j = 0; j < 26; ++j){
			A = B = (char)('a' + j);
			build_pi(t);
			A = (char)('a' + i);
			match(s, t, ok[i][j]);
//			exit(0);
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int ls, lt;
	string s, t;
	cin >> ls >> lt >> s >> t;

	build(s, t);

	vector<int> ans;

	for (int i = 0; i < SZ(s); ++i){
		last[s[i] - 'a'] = i + 1;
		bool valid = true;

//		DB(i + 1);

		for (int j = 0; j < 26 && valid; ++j){
			int c = last[j] - 1;
			if (c < 0) continue;
//			cout << j << " " << c << endl;
//			cout << (char)('a' + j) << " " << t[c - i - 1 + lt] << endl;

			if (c - i - 1 + lt >= 0 && c - i - 1 < 0){
				if (!ok[j][ t[c - i - 1 + lt] - 'a' ][i + 1]) valid = false;
				if (!ok[ t[c - i - 1 + lt] - 'a'][j][i + 1]) valid = false;
			}
		}
		if (valid) ans.push_back(i - lt + 2);
	}

	cout << SZ(ans) << endl;
	for (auto &p : ans)
		cout << p << " ";
	cout << endl;

	return 0;
}