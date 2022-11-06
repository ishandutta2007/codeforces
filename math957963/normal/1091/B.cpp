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
	int x[N];
	int y[N];
	int a[N];
	int b[N];
	set<pair<int, int> >sp;
	f(i, N){
		a[i] = 0;
		b[i] = 0;
		x[i] = 0;
		y[i] = 0;
	}
	int n, k;
	int xx, yy, zz;
	bool v = true;
	scanf("%d", &n);
	f(i, n){
		scanf("%d %d", &x[i],&y[i]);
	}
	f(i, n){
		scanf("%d %d", &a[i], &b[i]);
		sp.insert(make_pair(a[i], b[i]));
	}
	f(i, n){
		xx = x[0] + a[i];
		yy = y[0] + b[i];
		v = true;
		for(int j=1;j<n;j++){
			if (sp.count(make_pair(xx - x[j], yy - y[j])) == 0){
				v = false;
				break;
			}
		}
		if (v){
			printf("%d %d\n", xx, yy);
		}
	}

	return 0;
}