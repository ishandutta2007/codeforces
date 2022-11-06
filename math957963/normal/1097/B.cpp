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
	int a[20];
	int n;
	scanf("%d", &n);
	int t = 1 << n;
	int s,x;
	bool v = false;
	f(i, n)scanf("%d", &a[i]);
	f(i, t){
		s = 0;
		x = i;
		f(j, n){
			if (x % 2 == 1)s += a[j];
			else s -= a[j];
			x = x / 2;
		}
		if (s < 0)s = -s;
		if (s % 360 == 0)v = true;
	}

	if(v)printf("YES\n");
	else printf("NO\n");


	return 0;
}