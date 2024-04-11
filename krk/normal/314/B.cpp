#include <iostream>
#include <string>
using namespace std;

const int Maxn = 105;

int b, d;
string a, c;
int to[Maxn];
int per;
int res;

int main()
{
	cin >> b >> d;
	cin >> a >> c;
	int j;
	for (j = 0; j < c.length(); j++) {
		for (int i = 0; i < a.length(); i++)
			if (a[i] == c[(j + to[j]) % c.length()]) to[j]++;
		if (to[j] == 0) break;
	}
	if (j < c.length()) { cout << "0\n"; return 0; }
	int cur = 0;
	for (int k = 0; k < b; k++) {
		res += (cur + to[cur]) / c.length();
		cur = (cur + to[cur]) % c.length();
	}
	cout << res / d << endl;
	return 0;
}