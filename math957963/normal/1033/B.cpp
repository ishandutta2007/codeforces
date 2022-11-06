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
	int n, k;
	long long x, y, z;
	bool v = true;
	scanf("%d", &n);
	f(i, n){
		scanf("%I64d %I64d", &x, &y);
		if (x == (y + 1)){
			z = x + y;
			v = true;
			f(i, 1000000){
				if (i + 2 < z){
					if (z % (i + 2) == 0)v = false;
				}
			}
			if (v)printf("YES\n");
			else printf("NO\n");
		}

		else printf("NO\n");
	}

	return 0;
}