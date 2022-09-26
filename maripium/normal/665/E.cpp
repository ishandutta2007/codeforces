#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 5;

int n, k;
int x, pref;
int now = 0;

struct Trie{
	int have[2], child[2];
} a[N<<4];

void add(int x) {
	int pre = 0;
	for(int i = 30;i >= 0;--i) {
		int tem = (x>>i) & 1;
		if(!a[pre].have[tem]) a[pre].child[tem] = ++now;
		++a[pre].have[tem];
		pre = a[pre].child[tem];
	}
}

int query(int x,int lev,int pre) {
	int temx = (x >> lev) & 1;
	int temk = (k >> lev) & 1;
	if( temk == 1 ){
		if( lev == 0 || a[pre].have[temx^1] == 0) return a[pre].have[temx^1];
		return query(x, lev - 1,a[pre].child[temx^1]);
	}
	if(lev == 0) return a[pre].have[0] + a[pre].have[1];
	int ans = a[pre].have[temx^1];
	if(a[pre].have[temx]) ans += query(x,lev - 1,a[pre].child[temx]);
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cin >> n >> k;
	
	add(pref = 0);
	int ans = 0;
	for(int i = 0;i < n;++i){
		cin >> x;
		pref ^= x;
		ans += query(pref,30,0);
		add(pref);
	}
	
	cout << ans << endl;
	
}