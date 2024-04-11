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
#define N 200000
#define P 1000000

vector<long long>prim;
map<long long, long long>rp;
bool us[(P + 10)];

void prim_make(void) {
	f(i, P + 10)us[i] = true;
	us[0] = false;
	us[1] = false;
	long long nus;
	for (long long i = 2; i < (P + 10); i++) {
		if (us[i]) {
			prim.push_back(i);
			rp[i] = prim.size();
			nus = 2 * i;
			while (nus < (P + 10)) {
				us[nus] = false;
				nus += i;
			}
		}
	}
	return;
}

//prim_make
vector<pair<long long, long long> >pfact(long long k) {
	vector<pair<long long, long long> >re;
	long long cnt;
	if (k <= 1)return re;
	if (prim.size() == 0)prim_make();
	f(i, prim.size()) {
		if ((prim[i] * prim[i]) > k)break;
		cnt = 0;
		while (k%prim[i] == 0) {
			cnt++;
			k /= prim[i];
		}
		if (cnt > 0)re.push_back(make_pair(prim[i], cnt));

	}
	if (k > 1)re.push_back(make_pair(k, 1));
	return re;
}







int main() {
	vector<pair<long long, long long> >a;
	long long n, k, t;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	prim_make();
	scanf("%lld %lld", &k, &n);
	x = n;
	while (x > k) {
		a = pfact(x);
		if (a.size() > 0) {
			if (a[0].first > k) {
				printf("%lld\n", x);
				return 0;
			}
		}
		x--;
	}
	printf("-1\n");

	return 0;
}