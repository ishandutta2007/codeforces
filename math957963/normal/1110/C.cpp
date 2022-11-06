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
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000


int main(){
	int a[30];
	int b[30];
	int n, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	a[0] = 3;
	f(i, 23)a[i + 1] = (a[i] * 2) + 1;
	f(i, 30)b[i] = -1;
	scanf("%d", &n);
	f(i, n){
		scanf("%d", &x);
		v = false;
		f(i, 24){
			if (a[i] == x){
				z = i;
				v = true;
				break;
			}
			else if (a[i] > x){
				y = a[i];
				break;
			}
		}
		if (v){
			if (b[z] < 0){
				y = -1;
				for (int i = 2; (i*i) <= x; i++){
					if (x%i == 0){
						y = x / i;
						b[z] = y;
						break;
					}
				}
				if (y < 0){
					y = 1;
					b[z] = 1;
				}
			}
			else y = b[z];
		}
		printf("%d\n", y);
	}


	return 0;
}