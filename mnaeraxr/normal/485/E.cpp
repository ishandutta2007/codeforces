#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout<<#x<<"="<<x<<endl;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e6 + 10;

char s[MAXN];

struct PERM{
	int sz;
	vector<int> val;

	PERM(){
	}

	PERM(int SZ){
		sz = SZ;
		val = vector<int>(SZ);
	}

	PERM operator*(const PERM &a) const{
		PERM ans(sz);
		for (int i = 0; i < sz; ++i)
			ans.val[i] = val[a.val[i]];
		return ans;
	}
};

//void shift(PERM &p, int k){
//	k = (k + p.sz) % p.sz;
//	int *tmp = new int[p.sz];
//	for (int i = 0; i < p.sz; ++i)
//		tmp[i] = p.val[(i - k + p.sz) % p.sz];
//	for (int i = 0; i < p.sz; ++i)
//		p.val[i] = tmp[i];
//}

PERM identity(int sz, int dx = 0){
	PERM ans(sz);
	for (int i = dx, t = 0; t < sz; ++i){
		if (i < 0) i += sz;
		if (i >= sz) i -= sz;
		ans.val[i] = t++;
	}
	return ans;
}

PERM fast_exp(PERM a, int p){
	if (p == 0) return identity(a.sz);
	PERM ans = fast_exp(a * a, p / 2);
	if (p & 1) ans = a * ans;
	return ans;
}

int main()
{
	scanf("%s", s);
	int q;
	scanf("%d", &q);

	int len = strlen(s);

	PERM p = identity(len);

	while (q--){
		int k, d;
		scanf("%d%d", &k, &d);

		PERM C = identity(len);
		for (int i = 0, t = 0; i < d; ++i){
			for (int j = i; j < k; j += d){
				C.val[t++] = j;
			}
		}

		PERM SHIFT = identity(len, -1);
//		shift(SHIFT, -1);

		PERM cur = C * SHIFT;

		p = p * fast_exp(C * SHIFT, len - k + 1);

		SHIFT = identity(len, 1 - k);
//		shift(SHIFT, 1 - k);

		p = p * SHIFT;

		for (int i = 0; i < len; ++i)
			putchar(s[p.val[i]]);
		putchar('\n');
	}

	return 0;
}