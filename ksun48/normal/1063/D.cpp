#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

// 0 <= a <= p1, 0 <= b <= p2

// candies >= a
// (candies - a) % (n + a + b) = 1, 2 (b > 0);
// (candies - a) = (n + a + b) * k + 1
// (candies - a) = (n + a + b) * k + 2    (b > 0)

// if n <= 10^7 can do
// if n >= 10^7
LL solve1(LL p1, LL p2, LL candies, LL n){
	LL ans = -1;
	for(LL a = 0; a <= p1; a++){
		for(LL b = 0; b <= p2; b++){
			LL rc = candies - a;
			LL v = rc % (n + a + b);
			if(rc >= 0 && (v == 1 || (v == 2 && b > 0))){
				ans = max(ans, a+b);
			}
		}
	}
	return ans;
}
LL solve2(LL p1, LL p2, LL candies, LL n){
	LL ans = -1;
	for(LL sum = p1 + p2; sum >= 0; sum--){
		for(int rem = 1; rem <= 2; rem++){
			if(rem >= n + sum) continue;
			LL mina = 0;
			LL maxa = p1;
			mina = max(mina, sum - p2);
			maxa = min(maxa, sum - (rem == 2));
			maxa = min(maxa, candies);

			LL minc = candies - maxa;
			LL maxc = candies - mina;
			if(minc > maxc) continue;

			LL c = ((maxc - rem) / (n + sum)) * (n + sum) + rem;
			if(minc <= c && c <= maxc){
				ans = max(ans, sum);
			}
		}
	}
	return ans;
}
LL solve3(LL p1, LL p2, LL candies, LL n){
	LL ans = -1;
	LL maxcyc = candies / n;
	for(LL cyc = 0; cyc <= maxcyc; cyc++){
		for(LL rem = 1; rem <= 2; rem++){
			LL lhs = candies - rem;
			// lhs = (n + a + b) * cyc + a;
			if(lhs < 0) continue;
			if(cyc == 0){
				LL a = lhs;
				if(0 <= a && a <= p1){
					LL b = p2;
					if(rem < n + a + b){
						if(rem == 1 || b > 0){
							ans = max(ans, a + b);
						}
					}
				}
				continue;
			}
			// s * cyc + t = lhs
			// t in [0, p1], t <= lhs
			// s - t in [n (+ 1), n + p2]
			LL diffmin = n + (rem == 2);
			LL tmod = lhs % cyc;

			LL g = lhs - cyc * (n + p2);
			g = max(0LL, g);
			g = (g + cyc) / (cyc + 1);
			g = max(g, tmod);
			LL t = ((g - tmod + cyc - 1) / cyc) * cyc + tmod;
			if(t > p1 || t > lhs) continue;
			LL s = (lhs - t) / cyc;
			if(s-t < diffmin) continue;
			if(s-t > n + p2) continue;
			if(s <= rem) continue;
			ans = max(ans, s - n);
		}
	}
	return ans;
}

void test(){
	for(LL p1 = 0; p1 < 50; p1++){
		for(LL p2 = 0; p2 < 50; p2++){
			if(p1 == 0 && p2 == 0) continue;
			for(LL candies = 0; candies < 150; candies++){
				LL ans1 = solve1(p1, p2, candies, p1 + p2);
				LL ans2 = solve2(p1, p2, candies, p1 + p2);
				LL ans3 = solve3(p1, p2, candies, p1 + p2);
				if(ans1 != ans2 || ans1 != ans3){
					cerr << p1 << " " << p2 << " " << candies << " " << p1 + p2 << endl;
					cerr << ans1 << " " << ans2 << " " << ans3 << endl;
					exit(0);
				}
			}
		}
	}
	cerr << "done test" << endl;
}

int main(){
	cin.sync_with_stdio(0);
	//test();
	LL n, l, r, candies;
	cin >> n >> l >> r >> candies;
	l--; r--;
	r -= l; l -= l;
	if(r < 0) r += n;
	// number of sweet tooths in [r...l]
	LL p1 = r - l;
	LL p2 = n - p1;
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}

	candies -= p1;
	LL ans = -1;

	if(p1 + p2 <= 3e6){
		ans = solve2(p1, p2, candies, n);
	} else {
		ans = solve3(p1, p2, candies, n);
	}
	cout << ans << endl;
	cin.sync_with_stdio(0);
}