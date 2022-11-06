#include<cstdio>
#include<cstdlib>
#include <random>
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
	long long l, r, m, n;
	char a[10];
	long long k;
	long long s;
	bool v = true;
	scanf("%I64d %I64d", &n, &k);
	l = 0;
	r = n;
	s = 6 * k + 6;
	if (n < s)s = n;
	s--;
	if (s < 5)s = 5;
	std::random_device rnd;     // 
	std::mt19937 mt(rnd()); //  32
	std::uniform_int_distribution<> rand60(0, s);
	while (v){
		if (l + 6 * k + 6<r){
			m = (l + r) / 2;
			m--;
			printf("%I64d %I64d\n", l + 1, m + 1);
			fflush(stdout);
			scanf("%s", a);
			if (a[0] == 'Y'){
				r = m + 1;
			}
			else{
				l = m + 1;
			}
		}
		else{
			m = l + rand60(mt);
			if (m < n){
				printf("%I64d %I64d\n", m + 1, m + 1);
				fflush(stdout);
				scanf("%s", a);
				if (a[0] == 'Y'){
					v = false;
				}
			}
		}
		if (l - k > 0)l -= k;
		else l = 0;
		if (r + k < n)r += k;
		else r = n;
	}

	return 0;
}