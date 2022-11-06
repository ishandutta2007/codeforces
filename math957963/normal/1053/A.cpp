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

vector<long long>prim;

void prim_make(long long k){
	if (k >= 2)prim.push_back(2);
	if (k >= 3)prim.push_back(3);
	if (k >= 5)prim.push_back(5);
	long long x = 7;
	bool v;
	while (x <= k){
		v = true;
		for (int i = 2; prim[i] * prim[i] <= x; i++){
			if (x%prim[i] == 0){
				v = false;
				break;
			}
		}
		if (v)prim.push_back(x);
		if (x % 6 == 1)x += 4;
		else x += 2;
	}
	return;
}




int main(){
	long long x, y, k;
	long long s, ans;
	bool v = true;
	ans = 0;
	prim_make(40000);
	scanf("%I64d %I64d %I64d", &x, &y, &k);
	s = x*y * 2;
	if (s%k != 0){
		printf("NO\n");
		return 0;
	}
	f(i, prim.size()){
		if (k%prim[i] == 0){
			while (k%prim[i] == 0){
				if (x%prim[i] == 0){
					if (v){
						x = x * 2;
						v = false;
					}
					x = x / prim[i];
				}
				else {
					if (v){
						y = y * 2;
						v = false;
					}
					y = y / prim[i];
				}
				k = k / prim[i];
			}
		}
		if (k == 1)break;
	}
	if (k != 1){
		if (x%k == 0){
			if (v){
				x = x * 2;
				v = false;
			}
			x = x / k;
		}
		else{
			if (v){
				y = y * 2;
				v = false;
			}
			y = y / k;
		}
		k = 1;
	}
	printf("YES\n");
	printf("0 0\n");
	printf("%I64d 0\n", x);
	printf("0 %I64d\n", y);


	return 0;
}