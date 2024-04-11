#include <bits/stdc++.h>
using namespace std;

struct splitmix64_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

const int B = 80;
struct vec {
	uint32_t a[B];
};

struct FT {
	vector<vec> s;
	FT(int n) : s(n) {
		for(int i = 0; i < n; i++){
			for(int j = 0; j < B; j++){
				s[i].a[j] = 0;
			}
		}
	}
	void update(int pos, vec dif) { // a[pos] += dif
		for (; pos < s.size(); pos |= pos + 1){
			for(int i = 0; i < B; i++){
				s[pos].a[i] += dif.a[i];
			}
		}
	}
	vec query(int pos) { // sum of values in [0, pos)
		vec res;
		for(int i = 0; i < B; i++){
			res.a[i] = 0;
		}
		for (; pos > 0; pos &= pos - 1){
			for(int i = 0; i < B; i++){
				res.a[i] += s[pos-1].a[i];
			}
		}
		return res;
	}
};
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	splitmix64_hash H;
	int N, Q;
	cin >> N >> Q;
	vector<int> A(N);
	FT ft(N);
	for(int& x : A) cin >> x;
	vector<vec> Ah(N);
	auto get_hash = [&](int64_t x){
		vec res;
		for(int i = 0; i < B; i++){
			res.a[i] = (x & ((1 << 20) - 1)) % 9999;
			x = H(x);
		}
		return res;
	};
	for(int i = 0; i < N; i++){
		Ah[i] = get_hash(A[i]);
		ft.update(i, Ah[i]);
	}
	for(int q = 0; q < Q; q++){		
		int type;
		cin >> type;
		if(type == 1){
			int i, x;
			cin >> i >> x;
			i--;
			vec r = Ah[i];
			for(int j = 0; j < B; j++){
				r.a[j] = -r.a[j];
			}
			ft.update(i, r);
			A[i] = x;
			Ah[i] = get_hash(A[i]);
			ft.update(i, Ah[i]);
		} else if(type == 2){
			int l, r, k;
			cin >> l >> r >> k;
			l--;
			vec res1 = ft.query(l);
			vec res2 = ft.query(r);
			bool works = true;
			for(int i = 0; i < B; i++){
				if((res2.a[i] - res1.a[i]) % k != 0) works = false;
			}
			cout << (works ? "YES" : "NO") << '\n';
		} else assert(false);
	}
}