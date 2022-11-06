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
#define MOD 1000000007
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 1000010


int main(){
	long long a[N];
	long long l[N];
	long long r[N];
	priority_queue<pair<long long, long long> > pq;
	f(i, N)a[i] = 0;
	long long n, k;
	long long x, y, z;
	long long b, c, d;
	long long s, as, ans;
	bool v = true;
	ans = 0;
	scanf("%I64d %I64d", &n,&k);
	f(i, n){
		scanf("%I64d", &a[i]);
	}
	f(i, n){
		while (!pq.empty()){
			x = pq.top().second;
			if (a[x] < a[i]){
				r[x] = i;
				pq.pop();
			}
			else break;
		}
		pq.push(make_pair(-a[i], i));
	}
	while (!pq.empty()){
		x = pq.top().second;
			r[x] = n;
			pq.pop();
	}
	for (long long i = n - 1; i >= 0; i--){
		while (!pq.empty()){
			x = pq.top().second;
			if (a[x] <= a[i]){
				l[x] = i + 1;
				pq.pop();
			}
			else break;
		}
		pq.push(make_pair(-a[i], i));
	}
	while (!pq.empty()){
		x = pq.top().second;
		l[x] = 0;
		pq.pop();
	}
	k--;
	f(i, n){
		x = i - l[i];
		y = r[i] - i - 1;
		s = 0;
		b = x + y;
		b++;
		c = b / k;
		d = b%k;
		s = k*c*(c - 1);
		s = s / 2;
		s += (d*c);
		as = s;
		as = as%MOD;

		b = x - 1;
		b++;
		c = b / k;
		d = b%k;
		s = k*c*(c - 1);
		s = s / 2;
		s += (d*c);
		as -= s;
		as += MOD;
		as = as%MOD;

		b = y - 1;
		b++;
		c = b / k;
		d = b%k;
		s = k*c*(c - 1);
		s = s / 2;
		s += (d*c);
		as -= s;
		as += MOD;
		as = as%MOD;
		as = as*a[i];
		as = as%MOD;
		ans += as;
		ans = ans%MOD;

	}

	printf("%I64d\n", ans);


	return 0;
}