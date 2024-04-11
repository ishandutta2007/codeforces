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
	long long x, y, z;
	long long a, b, c;
	long long am, bm, cm;
	long long as, bs, cs;
	long long k, s, ans;
	scanf("%I64d %I64d", &x, &y);
	z = 0;
	if (y < x)swap(x, y);
	if (x == 1){
		if (y % 6 < 4)z = y % 6;
		else z = 6 - (y % 6);
	}
	else{
		if (x % 2 == 0 && y % 2 == 0){
			if (x == 2 && y == 2)z = 4;
		}
		else if (x % 2 == 0){
			if (x == 2){
				if (y == 3 || y == 7)z = 2;
			}
		}
		else if (y % 2 == 1)z = 1;
	}

		printf("%I64d\n", (x*y) - z);


	return 0;
}