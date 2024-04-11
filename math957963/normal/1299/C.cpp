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
#define N 1001000
	long long a[N];

int main() {

	f(i, N)a[i] = 0;
	stack < pair<long long, long long> >st;
	long long n, k;
	long long x, y, z,xx,yy,zz;
	long double s, ans;
	scanf("%I64d", &n);
	f(i, n) {
		scanf("%I64d", &a[n-i-1]);
	}
	f(i, n) {
		x = a[i];
		y = 1;
		while (!st.empty()) {
			xx = st.top().first;
			yy = st.top().second;
			z = x * yy;
			zz = xx * y;
			if (z >= zz) {
				x += xx;
				y += yy;
				st.pop();
			}
          else break;
		}
		st.push(make_pair(x, y));
	}
	while (!st.empty()) {
		xx = st.top().first;
		yy = st.top().second;
		s = ((long double)(((long double)(xx)) / ((long double)(yy))));
		st.pop();
		f(i, yy) {
			printf("%.11Lf", s);
			printf("\n");
		}
	}
	return 0;
}