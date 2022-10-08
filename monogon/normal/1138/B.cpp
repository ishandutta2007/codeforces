
#include <iostream>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

int n;
string c, a;
vector<int> s[2][2];
vector<int> f;

int main() {
	cin >> n >> c >> a;
	for(int i = 0; i < n; i++) {
		s[c[i] - '0'][a[i] - '0'].push_back(i + 1);
	}
	int na = s[0][0].size(), nb = s[0][1].size(), nc = s[1][0].size(), nd = s[1][1].size();
	for(int a = 0; a <= na; a++) {
		for(int b = 0; b <= nb; b++) {
			int d = a - n/2 + nb + nd;
			int c = nb + nd - b - 2 * d;
			if(0 <= c && c <= nc && 0 <= d && d <= nd) {
				for(int i = 0; i < a; i++) {
					cout << s[0][0][i] << " ";
				}for(int i = 0; i < b; i++) {
					cout << s[0][1][i] << " ";
				}for(int i = 0; i < c; i++) {
					cout << s[1][0][i] << " ";
				}for(int i = 0; i < d; i++) {
					cout << s[1][1][i] << " ";
				}
				return 0;
			}
		}
	}
	cout << -1 << endl;
}