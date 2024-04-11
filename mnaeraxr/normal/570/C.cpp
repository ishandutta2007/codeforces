#include <bits/stdc++.h>

using namespace std;

typedef pair<int,bool> node;

const int maxn = 300100;

int seq[maxn];
char s[maxn];

int main()
{
	int n, m;
	cin >> n >> m;
	cin >> s;

	seq[0] = 1;
	for (int i = 0; i < n; ++i)
		seq[i + 1] = (s[i] == '.') ? 0 : 1;


	int totz = 0, totp = 0;

	for (int i = 1; i <= n; ++i){
		if (seq[i] == 0) ++totz;
		if (seq[i] == 0 && seq[i - 1] == 1) ++totp;
	}

	for (int i = 0; i < m; ++i){
		int q;
		char c;
		cin >> q >> c;
		int v = c == '.' ? 0 : 1;

		if (seq[q] != v){

			if (v == 0){
				++totz;
				if (q + 1 <= n && seq[q + 1] == 0)
					--totp;
				if (seq[q - 1] == 1)
					++totp;
			}
			else{
				--totz;
				if (seq[q - 1] == 1)
					--totp;
				if (q + 1 <= n && seq[q + 1] == 0)
					++totp;
			}
		}

		seq[q] = v;
		cout << totz - totp << endl;
	}
}