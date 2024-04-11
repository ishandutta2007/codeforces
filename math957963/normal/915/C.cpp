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

int main(){
	long long a[20];
	long long n;
	long long m;
	long long mm;
	long long ans;
	long long ans2;
	long long k = 0;
	long long c[10];
	long long p10[19];
	long long x, y, z;
	p10[0] = 1;
	for (int i = 1; i < 19; i++)p10[i] = p10[i - 1] * 10;
	scanf("%I64d", &n);
	scanf("%I64d", &m);
	mm = m;
	for (int i = 0; i < 10; i++)c[i] = 0;
	ans = 0;
	k = 0;
	while (n > 0){
		c[(n % 10)]++;
		n = n / 10;
		k++;
	}
	x = 0;
	while (m > 0){
		a[x] = m % 10;
		m = m / 10;
		x++;
	}
	x = 0;
	for (int i = 0; i <10; i++){
		for (int j = 0; j < c[i]; j++){
			ans += (p10[x] * i);
			x++;
		}
	}
	if (ans <= mm){
		printf("%I64d\n", ans);

		return 0;
	}
	else{
		ans = 0;
		for (int i = 0; i < k; i++){
			for (int j = a[k - i - 1] - 1; j >= 0; j--){

				if (c[j] > 0){
					ans2 = ans;
					ans2 += (j * p10[k - i - 1]);
					c[j]--;
					x = 0;
					for (int ii = 0; ii <10; ii++){
						for (int jj = 0; jj < c[ii]; jj++){
							ans2 += (p10[x] * ii);
							x++;
						}
					}
					c[j]++;
					break;
				}
			}
			if (c[a[k-i-1]]>0){
				ans += (a[k - i - 1] * p10[k - i - 1]);
				c[a[k - i - 1]]--;
			}
			else {
				printf("%I64d\n", ans2);

				return 0;
			}
		}
	}

	printf("%I64d\n", ans);

	return 0;
}