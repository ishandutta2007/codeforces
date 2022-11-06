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
#define N 200000

int main(){
	vector<long long>a;
	long long n;
	long long x, y, z;
	scanf("%I64d", &n);
	for (long long i = 1; i <= n; i++){
		x = i;
		if ((x*x) > n)break;
		if (n%x == 0){
			y = n / x;
			z = (y - 1)*y;
			z = z / 2;
			z *= x;
			z += y;
			a.push_back(z);
			if (x != y){
				z = (x - 1)*x;
				z = z / 2;
				z *= y;
				z += x;
				a.push_back(z);
			}
		}
	}

	sort(a.begin(), a.end());
	f(i, a.size()){
		printf("%I64d", a[i]);
		if (i < a.size() - 1)printf(" ");
		else printf("\n");
	}


	return 0;
}