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
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N (524288)
long long bit[N + 1];
long long w[N + 1];
 
 
void init(void) {
	f(i, N + 1)bit[i] = 0;
	return;
}
 
 
void add(long long k, long long x) {
	while (k <= N) {
		bit[k] += x;
		k += k & -k;
	}
	return;
}
 
long long sum(long long r) {
	long long s = 0;
	while (r > 0) {
		s += bit[r];
		r -= r & -r;
	}
	return s;
}
 
 
int main() {
	long long a[N];
	long long b[N];
	set<long long>st;
	f(i, N) {
		a[i] = 0;
		b[i] = 0;
	}
	long long n, k;
	long long x, y, z, xx, yy, zz;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%I64d", &n);
	f(i, n) {
		scanf("%I64d", &k);
		a[k - 1] = i + 1;
	}
	init();
	auto itr = st.end();
	f(i, n) {
		if (i == 0) {
			add(a[0], (long long)1);
			b[0] = 0;
          st.insert(a[0]);
			y = a[0];
			printf("0");
		}
		else {
			x = sum(a[i]);
			xx = i - x;
			b[i] = b[i - 1] + max((long long)0, xx - x);
			add(a[i], (long long)1);
			x = a[i];
			xx = sum(a[i]);
			if (i % 2 == 0) {
				itr = st.find(y);
				itr++;
				z = (*itr);
				if (x < y) {
					yy = sum(y);
					b[i] += ((y - x) - (yy - xx));
					st.insert(x);
				}
				else if (z < x) {
					zz = sum(z);
					b[i] += ((x - z) - (xx - zz));
					st.insert(x);
					y = z;
				}
				else {
					st.insert(x);
					y = x;
				}
			}
			else {
				if (x < y) {
					yy = sum(y);
					b[i] += ((y - x) - (yy - xx));
					st.insert(x);
					itr = st.find(y);
					itr--;
					y = (*itr);
				}
				else {
					yy = sum(y);
					b[i] += ((x - y) - (xx - yy));
					st.insert(x);
				}
 
			}
			printf(" %I64d", b[i]);
		}
	}
	printf("\n");
 
 
	return 0;
}