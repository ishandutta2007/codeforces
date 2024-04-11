#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int d, m;
vector<int> gen;
vector<int> b;

map<LL, vector<LL> > dp_saved;

LL cnt(LL S, vector<LL> masks){
	assert(masks.size() > 0);
	if(S == 0) return 0;
	if(masks.size() == 1){
		if(!dp_saved.count(S)){
			LL Suse = S;
			vector<LL> digits;
			while(Suse > 0){
				digits.push_back(Suse % d);
				Suse /= d;
			}
			reverse(digits.begin(), digits.end());
			vector<LL> dp(m, 0);

			LL cursum = 0;
			for(LL digit : digits){
				vector<LL> newdp(m, 0);
				for(int i = 0; i < m; i++){
					for(int j = 0; j < d; j++){
						newdp[(i + gen[j]) % m] += dp[i];
					}
				}
				for(int j = 0; j < digit; j++){
					newdp[(cursum + gen[j]) % m] ++;
				}
				dp = newdp;
				cursum += gen[digit];
			}
			dp_saved[S] = dp;
		}

		vector<LL> dp = dp_saved[S];

		LL ret = 0;
		for(int i = 0; i < m; i++){
			if(masks[0] & (1LL << i)){
				ret += dp[i];
			}
		}
		return ret;
	} else {
		LL ret = 0;
		for(int xres = 0; xres < d; xres ++){
			LL len = masks.size();
			LL newlen = (len - 1 + xres) / d + 1;
			vector<LL> newmasks(newlen, (1LL << m) - 1);
			for(LL i = 0; i < len; i++){
				LL newidx = (i + xres) / d;
				LL diff = gen[(i + xres) % d];
				newmasks[newidx] &= (masks[i] >> diff) | (masks[i] << (m - diff));
			}
			LL newS = (S - xres + d - 1) / d;
			ret += cnt(newS, newmasks);
		}
		return ret;
	}
}

LL solve(LL maxs){
	// s in [0, maxs)
	vector<LL> masks;
	for(int r : b){
		LL mask = (1LL << m) - 1;
		for(int z = 0; z < m; z++){
			if(z > r){
				mask &= ~(1LL << z);
			}
		}
		masks.push_back(mask);
	}
	return cnt(maxs, masks);
}
int main(){
	cin >> d >> m;
	gen.resize(d);
	for(int i = 0; i < d; i++){
		cin >> gen[i];
	}
	int n;
	cin >> n;
	b.resize(n);
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	LL l, r;
	cin >> l >> r;
	l--; r--;
	LL ans = solve(r-n+2) - solve(l);
	cout << ans << endl;
}