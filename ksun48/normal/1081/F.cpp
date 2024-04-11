#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int n;

int t;

int flip = 0;

int query(int l, int r){
	cout << "? " << l+1 << " " << r+1 << endl;
	fflush(stdout);
	int a;
	cin >> a;
	if(a == -1) exit(0);
	return a;
}

int find_psum(int x){
	if(x == 0) return 0;
	if(x == n) return t;
	if(x >= 2 || (x == 1 && (n % 2 == 0))){
		int r = 0;
		if(n % 2 == x % 2) r++;
		//assert(x % 2 != (n-r) % 2);
		int ret = -1;
		int c0 = 0;
		int c1 = 0;
		int prev = t;
		while(ret == -1 || c0 != 0 || c1 != 0){
			int a = query(r, x-1);
			int diff = a - prev;
			if(c0 == 0 && c1 == 0 && (x - diff) % 2 == 0){
				assert(x >= diff);
				ret = (x - diff) / 2;
			}
			if(diff % 2 == 0){
				c0 ^= 1;
			} else {
				c1 ^= 1;
			}
			prev = a;
		}
		assert(prev == t);
		return ret;
	} else {
		int ret = -1;
		int c0 = 0;
		int c1 = 0;
		int prev = t;
		while(ret == -1 || c0 != 0 || c1 != 0){
			int a = query(1, n-1);
			int diff = a - prev;
			int z = n-1;
			if(c0 == 0 && c1 == 0 && (z - diff) % 2 == 0){
				assert(z >= diff);
				ret = (z - diff) / 2;
			}
			if(diff % 2 == 0){
				c0 ^= 1;
			} else {
				c1 ^= 1;
			}
			prev = a;
		}
		assert(prev == t);
		return t - ret;
	}
}

void output(string ans){
	cout << "! " << ans << endl;
	fflush(stdout);
}
int main(){
	cin >> n >> t;
	vector<int> z(n+1, 0);
	for(int i = 0; i <= n; i++){
		z[i] = find_psum(i);
	}
	string r;
	for(int i = 0; i < n; i++){
		r += ('0' + z[i+1] - z[i]);
	}
	output(r);
}