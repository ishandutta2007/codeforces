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
#define N 2000


int main(){
	int a[N];
	f(i, N)a[i] = 0;
	vector<int>b;
	int n, k;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	y = 0;
	f(i, n){
		scanf("%d", &x);
		a[i] = x - y;
		y = x;
	}
	for(int i=1;i<=n;i++){
		v = true;
		f(j, n){
			x = j%i;
			if (a[x] != a[j]){
				v = false;
				break;
			}
		}
		if (v)b.push_back(i);
	}

	printf("%d\n", b.size());
	f(i, b.size()){
		printf("%d", b[i]);
		if (i < b.size() - 1)printf(" ");
		else printf("\n");
	}


	return 0;
}