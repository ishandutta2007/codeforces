#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 123456789;
int n,m;
vector<int> pref,suff;
int be[N],en[N];
int bel[N];
int lis[N],lds[N];

int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cin >> n >> m;
	for(int i = 0;i < n;++i) {
		int l,r;
		cin >> l >> r;
		++be[l];	
		++en[r];
	}
	
	int cur = 0;
	for(int i = 1;i <= m;++i) {
		cur += be[i];
		bel[i] = cur;
		cur -= en[i];
	}
	
	pref.assign(N,INF);
	pref[1] = bel[1];
	lis[1] = 1;
	for(int i = 2;i <= m;++i) {
		int pos = upper_bound(pref.begin(),pref.end(),bel[i]) - pref.begin();
		pref[pos] = bel[i];
		lis[i] = pos;
	}
	
	suff.assign(N,INF);
	suff[1] = bel[m];
	lds[m] = 1;
	for(int i = m - 1;i >= 1;--i) {
		int pos = upper_bound(suff.begin(),suff.end(),bel[i]) - suff.begin();
		suff[pos] = bel[i];
		lds[i] = pos; 
	}
	
	int ans = 0;
	for(int i = 1;i <= m;++i) ans = max(ans,lis[i] + lds[i] - 1);
	cout << ans << endl;
}