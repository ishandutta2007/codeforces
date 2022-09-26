#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5;
int n,q,a[N];
int st[N << 2], mx[N << 2];

void build(int i,int l,int r) {
	if(l == r) {
		st[i] = mx[i] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(i << 1,l,mid);
	build(i << 1 | 1,mid + 1,r);
	st[i] = st[i << 1] + st[i << 1 | 1];
	mx[i] = max(mx[i << 1],mx[i << 1 | 1]);
}

void upd(int i,int l,int r,int L,int R,int mod) {
	if(L > r || R < l || mx[i] < mod) return;
	if(l == r) {
		a[l] %= mod;
		st[i] = mx[i] = a[l];
		return;
	}
	int mid = l + r >> 1;
	upd(i << 1,l,mid,L,R,mod);
	upd(i << 1 | 1,mid + 1,r,L,R,mod);
	st[i] = st[i << 1] + st[i << 1 | 1];
	mx[i] = max(mx[i << 1],mx[i << 1 | 1]);
}

void upd(int i,int l,int r,int pos,int val) {
	if(pos > r || pos < l ) return;
	if(l == r) {
		a[l] = val;
		st[i] = mx[i] = a[l];
		return;
	}
	int mid = l + r >> 1;
	upd(i << 1,l,mid,pos,val);
	upd(i << 1 | 1,mid + 1,r,pos,val);
	st[i] = st[i << 1] + st[i << 1 | 1];
	mx[i] = max(mx[i << 1],mx[i << 1 | 1]);
}

int query(int i,int l,int r,int L,int R) {
	if(L > r || R < l ) return 0;
	if(L <= l && R >= r) return st[i];
	int mid = l + r >> 1;
	return query(i << 1,l,mid,L,R) + query(i << 1 | 1,mid + 1,r,L,R);
}

signed main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;++i) cin >> a[i];
	build(1,1,n);
	while(q--) {
		int type,l,r,val,pos,mod;
		cin >> type;
		if(type == 1) {
			cin >> l >> r;
			cout << query(1,1,n,l,r) << endl;
		}
		else if(type == 2) {
			cin >> l >> r >> mod;
			upd(1,1,n,l,r,mod);
		}
		else {
			cin >> pos >> val;
			upd(1,1,n,pos,val);
		}
	}
	
}