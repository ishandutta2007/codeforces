#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf = 1e+9;

int main() {
	/*ifstream in("input.txt");
	ofstream out("output.txt");*/
	
	ll i, bres = 0, cres = 0;
	vector<ll> acnt(26, 0), bcnt(26, 0), ccnt(26, 0);

	string a, b, c;
	cin >> a >> b >> c;
	for (i = 0; i < a.size(); i++)
		acnt[a[i] - 'a']++;
	for (i = 0; i < b.size(); i++)
		bcnt[b[i] - 'a']++;
	for (i = 0; i < c.size(); i++)
		ccnt[c[i] - 'a']++;

	vector<ll> acnt2(acnt);

	ll curb = 0, curc;
	bool succ = true;
	for (curb = 0; succ; curb++) {
		curc = inf;
		for (i = 0; i < 26; i++)
			if (ccnt[i])
				curc = min(curc, acnt2[i] / ccnt[i]);
		if (curb + curc > bres + cres) {
			bres = curb;
			cres = curc;
		}
		for (i = 0; i < 26; i++) {
			acnt2[i] -= bcnt[i];
			if (acnt2[i] < 0)
				succ = false;
		}
	}

	for (i = 0; i < bres; i++) {
		cout << b;
	}
	for (i = 0; i < 26; i++)
		acnt[i] -= bcnt[i] * bres;

	for (i = 0; i < cres; i++) {
		cout << c;
	}
	for (i = 0; i < 26; i++)
		acnt[i] -= ccnt[i] * cres;

	for (i = 0; i < 26; i++)
		for (; acnt[i]; acnt[i]--)
			cout << char(i + 'a');

	return 0;
}