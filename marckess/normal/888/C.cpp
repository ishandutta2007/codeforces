#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

string s;
int n;

bool esPos (int m) {
	bitset<256> res;
	int acu[256] = {0};

	for (int i = 'a'; i <= 'z'; i++)
		res[i] = 1;

	int i = 0, j = 0;

	while (j < n) {
		while (j < i + m)
			acu[s[j++]]++;

		bitset<256> aux;
		for (int i = 'a'; i <= 'z'; i++)
			aux[i] = bool(acu[i]);

		res &= aux;
		acu[s[i++]]--;
	}

	return res.count();
}

int obtRes () {
	int i = 1, j = n+1, rep = 20;

	while (rep--) {
		int m = (i+j)/2;
		if (esPos(m))
			j = m;
		else
			i = m;
	}

	if (esPos(i))
		return i;
	return j;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s;
	n = s.size();

	cout << obtRes() << endl;

	return 0;
}