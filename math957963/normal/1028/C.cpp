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
#define f(i,n) for(int i=0;i<int(n);i++)
#define N (1<<20)

struct rect{
	int ll;
	int rr;
	int uu;
	int dd;
};

rect uni(rect a, rect b){
	rect c;
	c.ll = max(a.ll, b.ll);
	c.rr = min(a.rr, b.rr);
	c.uu = max(a.uu, b.uu);
	c.dd = min(a.dd, b.dd);
	return c;
}


int main(){
	rect r[N];
	int al[N];
	int ar[N];
	rect ans;
	int x;
	f(i, N){
		r[i].ll = -MOD;
		r[i].uu = -MOD;
		r[i].rr = MOD;
		r[i].dd = MOD;
	}
	int n, k;
	scanf("%d", &n);
	k = (1 << 18);
	f(i, n){
		scanf("%d %d %d %d", &r[k + i].ll, &r[k + i].uu, &r[k + i].rr, &r[k + i].dd);
	}
	f(i, k){
		al[k + i] = i;
		ar[k + i] = i + 1;
	}
	for (int i = k - 1; i > 0; i--){
		r[i] = uni(r[(2 * i)], r[(2 * i) + 1]);
		al[i] = min(al[(2 * i)], al[(2 * i) + 1]);
		ar[i] = max(ar[(2 * i)], ar[(2 * i) + 1]);
	}
	f(i, n){
		x = 1;
		ans.ll = -MOD;
		ans.uu = -MOD;
		ans.rr = MOD;
		ans.dd = MOD;
		f(j, 18){
			if (i < ar[(2 * x)]){
				ans = uni(ans, r[(2 * x) + 1]);
				x = x * 2;
			}
			else{
				ans = uni(ans, r[(2 * x)]);
				x = x * 2 + 1;
			}
		}
		if (ans.ll <= ans.rr&&ans.uu <= ans.dd){
			printf("%d %d\n", ans.ll, ans.uu);
			return 0;
		}
	}

	return 0;
}