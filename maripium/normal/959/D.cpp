#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

int n;
set<int> prm;
vector<int> dvs[N];
bool np[N];
bool ok = false;
bool chk[N];
int res[N];
void eratosthene() {
	np[0] = np[1] = 1;
	for (int i = 2;i < N;++i) {
		if(np[i]) continue;
		prm.insert(i);
		dvs[i].push_back(i);
		for (int j = i << 1;j < N;j += i) dvs[j].push_back(i),np[j] = 1;
	}
}

bool valid(int x) {
	for (int i = 0;i < dvs[x].size();++i) {
		if (chk[dvs[x][i]]) return false;
	}
	return true;
}

void solve(int p) {
	if(p == n + 1) return;
	int x;	cin >> x;
	int ans;
	if(ok) ans = *prm.begin(), prm.erase(ans);
	else if (valid(x)) {
		ans = x;
		for (int i = 0;i < dvs[x].size();++i) chk[dvs[x][i]] = 1,prm.erase(dvs[x][i]); 	
	}
	else {
		int mx = *prm.upper_bound(x);
		for (int i = x + 1;i <= mx;++i) 
			if(valid(i)) {
				ans = i;
				break;
			}
		for (int i = 0;i < dvs[ans].size();++i) chk[dvs[ans][i]] = 1,prm.erase(dvs[ans][i]);
		ok = true;
	}
	//cout << ans << ' ';
	res[p] = ans;
	solve(p + 1);
}
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(0);
	eratosthene();
	cin >> n;
	solve(1);
	for (int i = 1;i <= n;++i) cout << res[i] << ' ';
}