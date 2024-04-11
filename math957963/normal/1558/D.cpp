#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N (1<<19)
#define MOD 998244353
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
struct Setup_io {
	Setup_io() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cout << fixed << setprecision(15);
	}
} setup_io;

int nn;
int bit[N];
bool d[30];
ll k[N];
ll r[N];

void add(int k, int x) {
	while (k <= nn) {
		bit[k] += x;
		k += (k&(-k));
	}
}

int search(int l, int r, int val) {
	if ((l + 1) == r)return r;
	int mid = (l + r) / 2;
 // cout<<val<<" "<<bit[mid]<<" "<<mid<<endl;
	if (val + bit[mid] <= mid)return search(l, mid, val);
	else return search(mid, r, val + bit[mid]);
}


int main() {
	int t;
	int n, m;
	int b[N];
	int a[N];
	int x, y, z;
	int xxx, yyy;
	ll xx, yy, zz;
	k[0] = 1;
	r[0] = 1;
	x = MOD - 2;
	rep(i, 30) {
		if (x % 2 == 1)d[i] = true;
		else d[i] = false;
		x /= 2;
	}
	rep(i, N - 1) {
		xx = i + 1;
		k[i + 1] = (k[i] * xx) % MOD;
		r[i + 1] = 1;
		yy = k[i + 1];
		rep(j, 30) {
			if (d[j])r[i + 1] = (r[i + 1] * yy) % MOD;
			yy = (yy*yy) % MOD;
		}
	}
	rep(i, N)a[i] = -1;
	rep(i, N)b[i] = i;
	rep(i, N)bit[i] = 0;
	vi era;
	vi bera;
	vi aera;
	vector<pii> bb;
	cin >> t;
	rep(tt, t) {
		cin >> n >> m;
		bb.clear();
		nn = 1;
		xxx = 2*n-1;
		yyy = n;
		while (nn <= n)nn *= 2;
		rep(i, m) {
			cin >> x >> y;
			bb.pb({ 1 - x,y - 1 });
			b[x - 1] = y - 1;
			bera.pb(x - 1);
		}
      sort(all(bb));
		//  return 0;
		rep(i, bb.size()) {
			z = search(0, nn, bb[i].second + 1);
       //   cout<<"!"<< z<<endl;
			a[z - 1] = -bb[i].first;
          aera.pb(z-1);
			if (a[z - 1] > a[z])xxx--;
			add(z, 1);
          era.pb(z);
		}
//rep(i,n)cout<<a[i]<<" ";
		xx = k[xxx];
		xx = (xx*r[yyy]) % MOD;
		xx = (xx*r[xxx - yyy]) % MOD;
		cout << xx << endl;
		rep(i, era.size())add(era[i], -1);
		era.clear();
		rep(i, bera.size())b[bera[i]] = bera[i];
		bera.clear();
		rep(i, aera.size())a[aera[i]] = -1;
		aera.clear();
	}




	return 0;
}