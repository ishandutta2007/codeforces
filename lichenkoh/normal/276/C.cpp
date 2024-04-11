#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll unsigned long long

ll *t;
int cmp(const void *a, const void *b) {
	if (*(ll*)a > *(ll*)b) return -1;
	if (*(ll*)a < *(ll*)b) return 1;
	else return 0;
}

void ins(ll bot, ll top, ll l, ll r, ll ind) {
	if (bot >= l && top <= r) {
		//cout << "ind:" << ind << endl;
		t[ind]++;
		return;
	}
	ll mid = (bot+top-1)/2;
	if (l <= mid) {
		ins(bot,mid,l,r,ind*2);
	}
	if (r >= mid+1) {
		ins(mid+1,top,l,r,ind*2+1);
	}
	return;
}

ll lookup(ll bot, ll top, ll x, ll ind) {
	//cout << bot << ":" << top << ":" << x << ":" << ind << endl;
	if (bot == top) {
		//cout << bot << ":" << top << ":" << x << endl;
		assert(bot==x);
		return t[ind];
	}
	ll mid = (bot+top-1)/2;
	if (x <= mid) {
		return t[ind] + lookup(bot,mid,x,ind*2);
	}
	else if (x >= mid+1) {
		return t[ind] + lookup(mid+1,top,x,ind*2+1);
	}
	else {
		assert(false);
	}
}

int main() {
	ll n,q;
	cin >> n;
	cin >> q;
	ll *a = new ll[n];
	ll *h = new ll[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll range = pow(2,ceil(log(n)/log(2)))-1;
	ll tsize = pow(2,1+ceil(log(n)/log(2)));
	//cout << "tsize:" << tsize << "range:" << range << endl;
	t = new ll[tsize+10];
	for (ll i = 0; i < tsize+10; i++) {
		t[i] = 0;
	}
	for (ll i = 0; i < q; i++) {
		ll l,r;
		cin >> l;
		cin >> r;
		l--;
		r--;
		ins(0,range,l,r,1);
	}
	for (ll i = 0; i < n; i++) {
		h[i] = lookup(0,range,i,1);
	}
	qsort(a,n,sizeof(ll),cmp);
	qsort(h,n,sizeof(ll),cmp);
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		ans += a[i]*h[i];
	}
	cout << ans << endl;
	return 0;
}