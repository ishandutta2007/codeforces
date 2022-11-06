#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
using namespace std;
#define MOD 998244353
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 1000

long long gcd(long long x,long long y){
	if (x > y)swap(x, y);
	if (x < 0)return 1;
	if (x == 0)return y;
	if (y%x == 0)return x;
	else return gcd(y%x, x);
}

long long jup2(long long x){
	long long l = 0;
	long long r = 1500000000;
	long long m, z;
	while (l + 1 < r){
		m = (l + r) / 2;
		z = m*m;
		if (x == z)return m;
		else if (z < x)l = m;
		else r = m;
	}
	z = l*l;
	if (x == z)return l;
	else return -1;
}

long long jup3(long long x){
	long long l = 0;
	long long r = 1500000;
	long long m, z;
	while (l + 1 < r){
		m = (l + r) / 2;
		z = m*m*m;
		if (x == z)return m;
		else if (z < x)l = m;
		else r = m;
	}
	z = l*l*l;
	if (x == z)return l;
	else return -1;
}

long long jup4(long long x){
	long long l = 0;
	long long r = 40000;
	long long m, z;
	while (l + 1 < r){
		m = (l + r) / 2;
		z = m*m*m*m;
		if (x == z)return m;
		else if (z < x)l = m;
		else r = m;
	}
	z = l*l*l*l;
	if (x == z)return l;
	else return -1;
}


int main(){
	long long a[N];
	int b[N];
	set<long long>p;
	set<long long>p2;
	int n;
	long long s,ss, ans;
	ans = 1;
	scanf("%d", &n);
	f(i, n){
		scanf("%I64d", &a[i]);
		s = jup4(a[i]);
		if (s > 0){
			p.insert(s);
			b[i] = 4;
		}
		else{
			s = jup3(a[i]);
			if (s > 0){
				p.insert(s);
				b[i] = 3;
			}
			else{
				s = jup2(a[i]);
				if (s > 0){
					p.insert(s);
					b[i] = 2;
				}
				else b[i] = 0;
			}
		}
	}
	f(i, n){
		f(j, i){
			s = gcd(a[i], a[j]);
			if (s > 1){
				if (b[i] == 0){
					if (a[i] > s){
						p.insert(s);
						p.insert((a[i] / s));
						b[i] = 1;
					}
				}
				if (b[j] == 0){
					if (a[j] > s){
						p.insert(s);
						p.insert((a[j] / s));
						b[j] = 1;
					}
				}
			}
		}
	}

	f(i, n){
		if (b[i] == 0)p2.insert(a[i]);
	}

	auto itr = p.begin();
	while (itr != p.end()){
		s = *itr;
		ss = 0;
		f(i, n){
			while (a[i] % s == 0){
				ss ++;
				a[i] = a[i] / s;
			}
		}
		ans = ans*(ss + 1);
		ans = ans%MOD;
		itr++;
	}

	auto itr2 = p2.begin();
	while (itr2 != p2.end()){
		s = *itr2;
		ss = 0;
		f(i, n){
			if (a[i] == s)ss++;
		}
		ans = ans*(ss + 1);
		ans = ans%MOD;
		ans = ans*(ss + 1);
		ans = ans%MOD;
		itr2++;
	}


	printf("%I64d\n", ans);


	return 0;
}