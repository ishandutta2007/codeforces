/* Heroes Never Die. */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
#define mp(a, b) make_pair(a, b)
#define x first
#define y second
#define read(a) scanf("%d", &a)


int n;
string a, b;
int main() {
	cin >> n >> a >> b;
	LL q[2], w[2];
	memset(q, 0, sizeof q);
	memset(w, 0, sizeof w);
	for (int i = 0; i < n; i++) {
		if (a[i] == '0') {
			if (b[i] == '0') {
				q[0]++;
			}
			else {
				w[0]++;
			}
		}
		else {
			if (b[i] == '0') {
				q[1]++;
			}
			else {
				w[1]++;
			}
		}
	}
	cout << q[0] * q[1] + q[0] * w[1] + q[1] * w[0] << endl;
	return 0;
}