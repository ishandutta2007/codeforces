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




int main(){
	long double x[N];
	long double y[N];
	int p[N];
	int pm[N];
	f(i, N){
		x[i] = 0;
		y[i] = 0;
		p[i] = i;
		pm[i] = 1;
	}
	int n, c, d;
	long double s, s2;
	bool v;
	scanf("%d", &n);
	f(i, n){
		scanf("%Lf %Lf", &x[i], &y[i]);
	}
	if (n == 1){
		printf("1\n");
		return 0;
	}
	else if (n == 2){
		s = ((x[0] + x[1]) * (x[0] + x[1])) + ((y[0] + y[1]) * (y[0] + y[1]));
		if (s <= 2250000000000){
			printf("1 1\n");
			return 0;
		}
		else{
			printf("1 -1\n");
			return 0;
		}
	}
	c = 1;
	d = 2;
	p[0] = 0;
	pm[0] = 1;
	f(qq, n - 2){
		s = (x[0] * x[c]) + (y[0] * y[c]);
		if (s > 0)v = true;
		else v = false;
		s = s*s;
		s2 = ((x[0] * x[0]) + (y[0] * y[0])) * ((x[c] * x[c]) + (y[c] * y[c]));
		if (4 * s >= s2){
			if (v){
				x[0] -= x[c];
				y[0] -= y[c];
				p[c] = 0;
				pm[c] = -1;
				c = qq + 3;
			}
			else{
				x[0] += x[c];
				y[0] += y[c];
				p[c] = 0;
				pm[c] = 1;
				c = qq + 3;
			}
		}

		else{
			s = (x[0] * x[d]) + (y[0] * y[d]);
			if (s > 0)v = true;
			else v = false;
			s = s*s;
			s2 = ((x[0] * x[0]) + (y[0] * y[0])) * ((x[d] * x[d]) + (y[d] * y[d]));
			if (4 * s >= s2){
				if (v){
					x[0] -= x[d];
					y[0] -= y[d];
					p[d] = 0;
					pm[d] = -1;
					d = qq + 3;
				}
				else{
					x[0] += x[d];
					y[0] += y[d];
					p[d] = 0;
					pm[d] = 1;
					d = qq + 3;
				}
			}
			else{
				s = (x[c] * x[d]) + (y[c] * y[d]);
				if (s > 0)v = true;
				else v = false;
				s = s*s;
				s2 = ((x[c] * x[c]) + (y[c] * y[c])) * ((x[d] * x[d]) + (y[d] * y[d]));
				if (4 * s >= s2){
					if (v){
						if (c < d){
							x[c] -= x[d];
							y[c] -= y[d];
							p[d] = c;
							pm[d] = -1;
							d = qq + 3;
						}
						else{
							x[d] -= x[c];
							y[d] -= y[c];
							p[c] = d;
							pm[c] = -1;
							c = qq + 3;
						}
					}
					else{
						if (c < d){
							x[c] += x[d];
							y[c] += y[d];
							p[d] = c;
							pm[d] = 1;
							d = qq + 3;
						}
						else{
							x[d] += x[c];
							y[d] += y[c];
							p[c] = d;
							pm[c] = 1;
							c = qq + 3;
						}
					}
				}
			}
		}
	}

	if (c == n){
		s = ((x[0] + x[d]) * (x[0] + x[d])) + ((y[0] + y[d]) * (y[0] + y[d]));
		if (s <= 2250000000000)pm[d] = 1;
		else pm[d] = -1;
	}
	else{
		s = ((x[0] + x[c]) * (x[0] + x[c])) + ((y[0] + y[c]) * (y[0] + y[c]));
		if (s <= 2250000000000)pm[c] = 1;
		else pm[c] = -1;
	}

	f(i, n){
		if(p[i]!=i)pm[i] = pm[p[i]] * pm[i];
		printf("%d", pm[i]);
		if (i < n - 1)printf(" ");
		else printf("\n");
	}

	return 0;
}