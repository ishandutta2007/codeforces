#include <stdio.h>
#include <bits/stdc++.h>
#define st first
#define nd second
#define PQ priority_queue
#define MP make_pair

using ll = long long ;
using namespace std;
using pii = pair<int,int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
const int N =1e5 + 10;
const int MOD = 0;
char s[N];
bool special[30];
void solve() {
	for (int i = 0; i <= 26; i++) special[i] = false;
	char lit[3];
	int n;
	cin >> n;
	cin >> s + 1;
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> lit;
		special[lit[0] - 'a'] = true;
	}
	int pos = 0, ma = 0;
	for (int i = n; i > 0; i--) {
		int x = s[i] - 'a';
		ma = max(ma, pos - i);
		if (special[x]) pos = i;
	}
	cout << ma << '\n';


}

int main(){
    cin.tie(0)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}


}