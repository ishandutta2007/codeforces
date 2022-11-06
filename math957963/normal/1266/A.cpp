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
#define f(i,n) for(int i=0;i<(int)(n);i++)
#define N 210


int main() {
	char a[N];
	f(i, N)a[i] = 0;
	int n, k;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &k);
	f(kk, k) {
		f(i, N)a[i] = 0;
		scanf("%s", a);
		n = strlen(a);
		v = true;
		f(i, n)if (a[i] != '0')v = false;
		if(v)printf("red\n");
		else {
			s = 0;
			f(i, n) {
				if (a[i] == '0')v = true;
				if ((a[i] - '0') % 2 == 0)s++;
			}
			if (s < 2)v = false;
			s = 0;
			f(i, n) {
				s += (a[i] - '0');
			}
			if (s % 3 != 0)v = false;
			if (v)printf("red\n");
			else printf("cyan\n");
		}
	}


	return 0;
}