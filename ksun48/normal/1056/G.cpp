#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL calc(LL x, LL n, LL m){
	LL cur = 1;
	LL pos = x;
	int dostep = 0;
	while(cur < n){
		LL newpos = pos;
		if(newpos < m){
			newpos -= cur;
		} else {
			newpos += cur;
		}
		newpos %= n;
		if(newpos < 0) newpos += n;
		if(dostep){
			pos = newpos;
			cur++;
			dostep = 0;
			continue;
		}
		if((pos < m) == (newpos < m)){
			if(pos < m && newpos < m){
				dostep = 1;
				continue;
			} else if(pos >= m && newpos >= m){
				// help
			}
			dostep = 1;
			continue;
		} else {
			if(pos < m && newpos >= m){
				LL r = (n - cur) / 2;
				r = min(r, (m-1-pos));
				r = min(r, newpos - m);
				pos += r;
				cur += 2 * r;
				if(r == 0) dostep = 1;
				continue;
			} else if(pos >= m && newpos <= m){
				dostep = 1;
				continue;
			}
		}
	}
	return pos;
}

LL blazing(LL n, LL m, LL s, LL t){
	LL a = s;
	LL curt = t;
	while(1){
		if(a < m){
			a += curt;
		} else {
			a -= curt;
		}
		a %= n;
		if(a < 0) a += n;

		curt --;
		if(curt % n == 0) break;
	}
	LL rounds = curt / n;
	map<LL,LL> occ;

	LL pos = a;
	while(rounds > 0){
		LL cur = 1;
		if(occ.find(pos) != occ.end()){
			LL period = occ[pos] - rounds;
			rounds %= period;
		}
		occ[pos] = rounds;
		if(rounds > 0){
			pos = calc(pos, n, m);
			/*while(cur < n){
				if(pos < m){
					pos -= cur;
				} else {
					pos += cur;
				}
				pos %= n;
				if(pos < 0) pos += n;
				cur++;
			}*/
			rounds--;
		}
	}
	return pos;
}

int main(){
	LL n, m, s, t;
	cin >> n >> m >> s >> t;
	s = s-1;
	cout << blazing(n, m, s, t) + 1 << '\n';
}