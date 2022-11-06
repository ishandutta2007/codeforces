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
	int a[N];
	int b[N+1];
	bool c[N];
	int n, x;
	bool v;
	scanf("%d", &n);
	f(i, n){
		scanf("%d", &a[i]);
		b[a[i]] = i;
	}
	for(int i=n;i>0;i--){
		x = b[i]-((b[i] / i)*i);
		v = false;
		while (x < n){
			if (a[x]>i){
				if (!c[x])v = true;
			}
			x += i;
		}
		c[b[i]] = v;
	}

	f(i, n){
		if(c[i])printf("A");
		else printf("B");
	}
	printf("\n");


	return 0;
}