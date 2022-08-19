#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
int n;
int sing = 0;
int x, y;
int ok = 1;
vector<int> a, b;
map<int,int> ps;

vector<vector<int> > af, bf, bfr;
vector<int> rt;

vector<int> plist;

LL lcm(LL a, LL b){
	return (a/__gcd(a,b)) * b;
}


LL inv(LL m1, LL m2){
	if(m1 >= m2) return inv(m1 % m2, m2);
	if(m2 == 1) return 0;
	LL d = inv(m1, m2-m1);
	return (d*m2-1)/(m2-m1);
}
pair<LL,LL> solve(pair<LL,LL> f1, pair<LL,LL> f2){
	LL c1 = f1.first;
	LL d1 = f1.second;
	LL c2 = f2.first;
	LL d2 = f2.second;
	LL cdiff = c1 - c2;
	LL r = __gcd(d1,d2);
	if(cdiff % r != 0){
		return make_pair(-1,-1);
	}
	d1 /= r;
	d2 /= r;
	cdiff /= r;

	LL av = inv(d1,d2);
	av %= d2;
	av *= (-cdiff);
	av %= d2;
	while(av < 0) av += d2;
	return make_pair(c1 + r*d1*av, d1*d2*r);
}

LL powmod(LL a, LL n){
	if(n == 0) return 1;
	if(n % 2) return (powmod(a,n-1) * a) % MOD;
	return powmod((a*a) % MOD, n/2);
}
int main(){
	cin >> n;
	for(int i = 0, c, d; i < n; i++){
		cin >> c >> d;
		a.push_back(c);
		b.push_back(d);
		if(d == 1){
			sing = 1;
			x = i;
			y = (i+1)%n;
		}
	}
	if(n == 1){
		cout << a[0] << endl;
		return 0;
	}
	for(int i = 0; i < a.size(); i++){
		int d = a[i];
		for(int p = 2; p*p <= d; p++){
			while(d % p == 0){
				d /= p;
				ps[p] = 1;
			}
		}
		if(d > 1) ps[d] = 1;
	}
	for(int i = 0; i < b.size(); i++){
		int d = b[i];
		for(int p = 2; p*p <= d; p++){
			while(d % p == 0){
				d /= p;
				ps[p] = 1;
			}
		}
		if(d > 1) ps[d] = 1;
	}
	for(map<int,int>::iterator it = ps.begin(); it != ps.end(); it++){
		plist.push_back(it->first);
	}
	af.resize(n); bf.resize(n); bfr.resize(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < plist.size(); j++){
			af[i].push_back(0);
			while(a[i] % plist[j] == 0){
				a[i] /= plist[j];
				af[i][j]++;
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < plist.size(); j++){
			bf[i].push_back(0);
			while(b[i] % plist[j] == 0){
				b[i] /= plist[j];
				bf[i][j]++;
			}
		}
		int g = 0;
		if(sing) g = 1;
		for(int j = 0; j < plist.size(); j++){
			if(bf[i][j] == 0) continue;
			if(g == 0) g = bf[i][j];
			g = __gcd(g,bf[i][j]);
		}
		for(int j = 0; j < plist.size(); j++){
			bfr[i].push_back(bf[i][j]/g);
		}
		rt.push_back(g);
	}
	for(int i = 0; i < n; i++){
		if(sing) continue;
		for(int j = 0; j < n; j++){
			if(sing) continue;
			for(int c = 0; c < plist.size(); c++){
				if(bfr[i][c] != bfr[j][c]){
					sing = 1;
					x = i;
					y = j;
					break;
				}
			}
		}
	}
	if(!sing){
		vector<int> z = bfr[0];
		vector<int> c;
		vector<int> d;
		for(int i = 0; i < n; i++){
			d.push_back(rt[i]);
			c.push_back(0);
			while(1){
				int ok = 1;
				for(int j = 0; j < plist.size(); j++){
					if(af[i][j] < z[j]) ok = 0;
				}
				if(!ok) break;
				for(int j = 0; j < plist.size(); j++){
					af[i][j] -= z[j];
				}
				c[i]++;
			}
		}
		int works = 1;
		for(int i = 0; i < n; i++){
			if(!works) continue;
			for(int j = 0; j < n; j++){
				if(!works) continue;
				for(int r = 0; r < plist.size(); r++){
					if(af[i][r] != af[j][r]){
						works = 0;
						break;
					}
				}
			}
		}
		if(!works){
			cout << -1 << endl;
			return 0;
		}
		pair<LL,LL> cur = make_pair(0,1);
		for(int i = 0; i < n; i++){
			cur = solve(cur, make_pair(c[i], d[i]));
			if(cur.second == -1){
				works = 0;
				break;
			}
		}
		if(!works){
			cout << -1 << endl;
			return 0;
		}
		for(int i = 0; i < n; i++){
			while(cur.first < c[i]){
				cur.first += cur.second;
			}
		}
		LL ans = 1;
		for(int i = 0; i < plist.size(); i++){
			ans = (ans * powmod(plist[i], af[0][i])) % MOD;
			ans = (ans * powmod(plist[i], z[i]*cur.first )) % MOD;
		}
		cout << ans << endl;
		return 0;
	}

	// solve single case
	for(int z = 0; z < 4000; z++){
		vector<LL> num;
		for(int i = 0; i < plist.size(); i++){
			num.push_back(af[x][i] + z*bf[x][i]);
		}
		int works = 1;
		for(int v = 0; v < n; v++){
			if(!works) break;
			LL t = -1;
			for(int i = 0; i < plist.size(); i++){
				if(!works) break;
				if(af[v][i] > num[i]){
					works = 0;
					break;
				}
				if(bf[v][i] == 0){
					if(af[v][i] != num[i]){
						works = 0;
						break;
					}
					continue;
				}
				if( (num[i] - af[v][i]) % bf[v][i] != 0) {
					works = 0;
					break;
				}
				LL mult = (num[i] - af[v][i]) / bf[v][i];
				if(t == -1) t = mult;
				if(t != mult){
					works = 0;
					break;
				}
			}
		}
		if(works){
			LL ans = 1;
			for(int i = 0; i < plist.size(); i++){
				ans = (ans * powmod(plist[i], num[i])) % MOD;
			}
			cout << ans << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}