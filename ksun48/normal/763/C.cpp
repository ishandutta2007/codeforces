#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL powmod(LL a, LL n, LL p){
	if(a == 0) return 0;
	if(n == 0) return 1;
	if(n % 2) return (a*powmod(a,n-1,p)) % p;
	LL c = powmod(a,n/2,p);
	return (c*c) % p;
}
LL inv(LL a, LL p){
	return powmod(a,p-2,p);
}

map<LL,LL> vals;
vector<LL> fact;
LL solve (LL a, LL b, LL m) {
    LL n = (LL) sqrt (m + .0) + 1;

    LL an = 1;
    for (LL i=0; i<n; ++i)
        an = (an * a) % m;

    for (LL i=1, cur=an; i<=n; ++i) {
        if (!vals.count(cur))
            vals[cur] = i;
        cur = (cur * an) % m;
    }

    for (LL i=0, cur=b; i<=n; ++i) {
        if (vals.count(cur)) {
            LL ans = vals[cur] * n - i;
            if (ans < m)
                return ans;
        }
        cur = (cur * a) % m;
    }
    return -1;
}

LL generator (LL p) {
    LL phi = p-1,  n = phi;
    for (LL i=2; i*i<=n; ++i)
        if (n % i == 0) {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);

    for (LL res=2; res<=p; ++res) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= powmod (res, phi / fact[i], p) != 1;
        if (ok)  return res;
    }
    return -1;
}
LL zz[110000], a[110000];
map<int,int> freq;

int a1[110000];
int m1, n1;
int main(){
	scanf("%d%d", &m1, &n1);

	for(int i = 0; i < n1; i++){
		scanf("%d", &a1[i]);
	}

	LL m = m1;
	LL n = n1;

	for(LL i = 0; i < n; i++) a[i] = a1[i];
	if(n == 1){
		cout << a[0] << " " << 0 << endl;
		return 0;
	}

	sort(a,a+n);


	for(LL i = 0; i < n; i++){
		freq[a[i]]++;
	}


	if(m == 2){
		if(freq[1] == 0){
			cout << 0 << " " << 0 << endl;
		} else if(freq[0] == 0){
			cout << 1 << " " << 0 << endl;
		} else if(freq[0] == freq[1]){
			cout << 0 << " " << 1 << endl;
		} else if(freq[0] == freq[1] + 1){
			cout << 0 << " " << 1 << endl;
		} else if(freq[1] == freq[0] + 1){
			cout << 1 << " " << 1 << endl;
		} else {
			cout << -1 << endl;
		}
		return 0;
	}
	for(LL i = 0; i < n; i++){
		if(freq[a[i]] == n){
			cout << a[i] << " " << 0 << endl;
			return 0;
		}
	}	
	if(n % m == 0){
		LL d = n/m;
		for(LL i = 0; i < m; i++){
			if(freq[i] != d){
				cout << -1 << endl;
				return 0;
			}
		}
		cout << 0 << " " << 1 << endl;
		return 0;
	}
	if(n % m == 1){
		LL f = -1;
		LL d = (n-1)/m;
		for(LL i = 0; i < m; i++){
			if(freq[i] < d){
				cout << -1 << endl;
				return 0;
			} else if(freq[i] == d+1){
				f = i;
			}
		}
		if(f >= 0){
			cout << f << " " << 1 << endl;
		} else {
			cout << -1 << endl;
		}
		return 0;
	}
	if(n % m == m-1){
		LL f = -1;
		LL d = (n+1)/m;
		for(LL i = 0; i < m; i++){
			if(freq[i] > d){
				cout << -1 << endl;
				return 0;
			} else if(freq[i] == d-1){
				f = i;
			}
		}
		if(f >= 0){
			cout << (f+1)%m << " " << 1 << endl;
		} else {
			cout << -1 << endl;
		}
		return 0;
	}

	LL inv2 = inv(2, m);
	LL sum = 0;
	LL ssq = 0;
	for(LL i = 0; i < n; i++){
		a[i] = (a[i] * 2) % m;
		sum += a[i];
		sum %= m;		

		ssq += (a[i]*a[i]) % m;
		ssq %= m;
	}
	LL x = inv((n) % m, m);
	x = (sum * x) % m;

	//cout << "x " << x << endl;

	LL qq = ssq - (((x*x) % m)*((n)%m)) % m;
	qq %= m;
	qq = (qq + m) % m;

	//cout << "qq" << qq << endl;

	LL f = 0;
	for(LL i = (n-1); i >= -(n-1); i -= 2){
		f += (i*i) % m;
		f %= m;
	}
	if(f == 0){
		cout << -1 << endl;
		return 0;
	}
	qq = qq * inv(f,m);
	qq %= m;

	//cout << "qq " << qq << endl;


	LL gen = generator(m);
	LL ec = solve(gen,qq,m);
	if(ec % 2 == 1){
		cout << -1 << endl;
		return 0;
	}
	LL d = powmod(gen,ec / 2,m);

	//cout << "d" << d << endl;
	if(d == -1){
		cout << -1 << endl;
		return 0;
	}
	if(d == 0){
		cout << -1 << endl;
		return 0;
	}

	for(LL i = 0; i < n; i++){
		zz[i] = x - ((n-1)*d)%m + i*(2*d)%m;
		zz[i] %= m;
		zz[i] += m;
		zz[i] %= m;
		//cout << zz[i] << " ";
	}
	//cout<< endl;
	sort(zz,zz+n);

	sort(a,a+n);
	for(LL i = 0; i < n; i++){
		if(a[i] != zz[i]){
			cout << -1 << endl;
			return 0;
		}		
	}
	LL pp = x - (n-1)*d;
	x = (x * inv(2,m)) % m;
	d = d % m;
	pp %= m;
	pp *= inv(2,m);
	pp =(pp % m + m) % m;
	cout << pp << " " << d << endl;
	return 0;
}