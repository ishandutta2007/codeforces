#include <bits/stdc++.h>
#define par pair<int, int>
#define mp make_pair
#define x first
#define y second
#define sz(a) int((a).size())
using namespace std;
string a, b;
int n, k;
vector<int> pos1, pos2;

void rever(int p, int q, vector<int> &pos, vector<par> &opt) {
	int l = pos[p] + 1, r = pos[q];
	if(q - p == r - l + 1) return;
	opt.push_back(mp(l, r));
	reverse(pos.begin() + p + 1, pos.begin() + q + 1);
	for(int j = p + 1; j <= q; j++) {
		pos[j] = l + r - pos[j];
	}
	return;
}
void reverr(int p, int q, vector<int> &pos, vector<par> &opt) {
	int l = pos[p], r = pos[q] - 1;
	if(q - p == r - l + 1) return;
	opt.push_back(mp(l, r));
	reverse(pos.begin() + p, pos.begin() + q);
	for(int j = p; j < q; j++) {
		pos[j] = l + r - pos[j];
	}
	return;
}

void calc(vector<int> &pos, vector<par> &opt) {
	if(k >= sz(pos) || k == 0) return;
	int n = sz(pos);
	for(int i = 1; i + k - 1 < n; i++) {
		rever(i - 1, i + k - 1, pos, opt);
	}
	for(;; ) {
		int flag = 0;
		if(k & 1) {
			for(int i = 1; i < sz(pos); i++) {
				if(pos[i] != pos[i - 1] + 1) {
					flag = 1;
				}
			}
		} else {
			for(int i = 1; i < sz(pos); i++) {
				if(i == sz(pos) - 1 - k) continue; 
				if(pos[i] != pos[i - 1] + 1) {
					flag = 1;
				}
			}			
		}
		if(!flag) break;
		if(k & 1) rever(n - k - 2, n - 2, pos, opt);
		else reverr(n - k - 1, n - 1, pos, opt);
		rever(n - k - 1, n - 1, pos, opt);
	}
	return;
}

void special(string a, string b) {
	int xa = 0, xb = 0;
	for(; a[xa] == '0'; xa++);
	for(; b[xb] == '0'; xb++);
	reverse(a.begin() + xa, a.end());
	reverse(b.begin() + xb, b.end());
	int ya = sz(a) - 1, yb = sz(b) - 1;
	for(; a[ya] == '0'; ya--);
	for(; b[yb] == '0'; yb--);
	int za = 0;
	for(; a[za] == '0'; za++);
	if(a == b) {
		cout << 2 << endl;
		cout << xa + 1 << " " << sz(a) << endl;
		cout << xb + 1 <<" " << sz(b) << endl;
		return;
	} 
	reverse(a.begin() + za, a.begin() + ya + 1);
	if(a == b) {
		cout << 3 << endl;
		cout << xa + 1 <<" " << sz(a) << endl;
		cout << za + 1 <<" " << ya + 1 << endl;
		cout << xb + 1 <<" " << sz(b) << endl;
		return;
	}
	cout << -1 << endl;
	return;
}

void solve() {
	pos1.clear(), pos2.clear();
	vector<par> opt1, opt2;
	cin >> n >> k;
	cin >> a >> b;
	
	pos1.push_back(0);
	pos2.push_back(0);
	for(int i = 0; i < n; i++) {
		if(a[i] == '1') pos1.push_back(i + 1);
		if(b[i] == '1') pos2.push_back(i + 1); 
	}
	if(sz(pos1) != sz(pos2)) {
		cout << -1 << endl;
		return ;
	}
	if(k == sz(pos1) - 1 && k) {
		special(a, b);
		return;
	}
	calc(pos1, opt1), calc(pos2, opt2);
	if(pos1 != pos2) {
		cout << -1 << endl;
		return; 
	}
	cout << sz(opt1) + sz(opt2) << endl;
	for(int i = 0; i < sz(opt1); i++) {
		cout << opt1[i].x <<" " << opt1[i].y << endl;
	}
	for(int i = sz(opt2) - 1; i >= 0; i--) {
		cout << opt2[i].x <<" " << opt2[i].y << endl;
	}
	return;
}

int main() {
	int T;
	for(cin >> T; T--; ) {
		solve();
	}
    return 0;
}