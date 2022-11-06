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
#define N 200000

int gc(int x, int y){
	if (x > y)swap(x, y);
	if (x == 0)return y;
	y = y%x;
	return gc(y, x);
}


int main(){
	int n, m, k, q;
	int a, b, x, y;
	int dn, dm, dk, dnm, dnk, dkm, d;
	int ans;
	scanf("%d", &q);
	f(qq, q){
		scanf("%d %d %d", &n,&m,&k);
		ans = 0;

		x = n;
		a = 2;
		dn = 1;
		while ((a*a) <= x&&x > 1){
			if (x%a == 0){
				b = 1;
				while (x%a == 0){
					b++;
					x = x / a;
				}
				dn = dn*b;
			}
			a++;
		}
		if (x > 1)dn = dn * 2;

		x = m;
		a = 2;
		dm = 1;
		while ((a*a) <= x&&x > 1){
			if (x%a == 0){
				b = 1;
				while (x%a == 0){
					b++;
					x = x / a;
				}
				dm = dm*b;
			}
			a++;
		}
		if (x > 1)dm = dm * 2;

		x = k;
		a = 2;
		dk = 1;
		while ((a*a) <= x&&x > 1){
			if (x%a == 0){
				b = 1;
				while (x%a == 0){
					b++;
					x = x / a;
				}
				dk = dk*b;
			}
			a++;
		}
		if (x > 1)dk = dk * 2;

		x = gc(n, m);
		a = 2;
		dnm = 1;
		while ((a*a) <= x&&x > 1){
			if (x%a == 0){
				b = 1;
				while (x%a == 0){
					b++;
					x = x / a;
				}
				dnm = dnm*b;
			}
			a++;
		}
		if (x > 1)dnm = dnm * 2;

		x = gc(n, k);
		a = 2;
		dnk = 1;
		while ((a*a) <= x&&x > 1){
			if (x%a == 0){
				b = 1;
				while (x%a == 0){
					b++;
					x = x / a;
				}
				dnk = dnk*b;
			}
			a++;
		}
		if (x > 1)dnk = dnk * 2;

		x = gc(k, m);
		y = x;
		a = 2;
		dkm = 1;
		while ((a*a) <= x&&x > 1){
			if (x%a == 0){
				b = 1;
				while (x%a == 0){
					b++;
					x = x / a;
				}
				dkm = dkm*b;
			}
			a++;
		}
		if (x > 1)dkm = dkm * 2;

		x = gc(n, y);
		a = 2;
		d = 1;
		while ((a*a) <= x&&x > 1){
			if (x%a == 0){
				b = 1;
				while (x%a == 0){
					b++;
					x = x / a;
				}
				d = d*b;
			}
			a++;
		}
		if (x > 1)d = d * 2;
		dnm -= d;
		dkm -= d;
		dnk -= d;
		dn -= (dnm + dnk + d);
		dm -= (dnm + dkm + d);
		dk -= (dnk + dkm + d);

		ans += (dn*dm*dk);

		ans += (dn*dm*dnk);
		ans += (dn*dm*dkm);
		ans += (dn*dm*d);

		ans += (dn*dnm*dk);
		ans += (dn*dkm*dk);
		ans += (dn*d*dk);

		ans += (dnk*dm*dk);
		ans += (dnm*dm*dk);
		ans += (d*dm*dk);

		ans += (dn*dnm*dnk);
		ans += (dn*dnm*dkm);
		ans += (dn*dnm*d);
		ans += (dn*dnk*dkm);
		ans += (dn*dnk*d);
		ans += (dn*dkm*d);

		ans += (dm*dnm*dnk);
		ans += (dm*dnm*dkm);
		ans += (dm*dnm*d);
		ans += (dm*dnk*dkm);
		ans += (dm*dnk*d);
		ans += (dm*dkm*d);

		ans += (dk*dnm*dnk);
		ans += (dk*dnm*dkm);
		ans += (dk*dnm*d);
		ans += (dk*dnk*dkm);
		ans += (dk*dnk*d);
		ans += (dk*dkm*d);

		ans += (dkm*dnm*dnk);
		ans += (d*dnm*dkm);
		ans += (dnk*dnm*d);
		ans += (dnk*d*dkm);

		ans += (dn + dnk + dnm + d)*((dkm*(dkm + 1)) / 2);

		ans += (dm + dkm + dnm + d)*((dnk*(dnk + 1)) / 2);

		ans += (dk + dnk + dkm + d)*((dnm*(dnm + 1)) / 2);

		ans += (dn + dk + dm + dnk + dnm + dkm)*((d*(d + 1)) / 2);

		ans += ((d*(d + 1)*(d + 2)) / 6);

		printf("%d\n", ans);

	}


	return 0;
}