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
#define N (200000)


int n;
vector<int>e[N];
long double a[N];
long long d[N];
bool used[N];

void init(void){
	memset(used, 0, sizeof(used));
	f(i, N)a[i] = 0;
	return;
}



int main(void){
	int k;
	int x, y;
	long double s, ans;
	scanf("%d %Lf", &n, &ans);
	ans = ans*2;
	f(i, n-1){
		scanf("%d %d", &x, &y);
		x--;
		y--;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	s = 0;
	f(i, n){
		if (e[i].size() == 1)s += 1;
	}
	ans = ans / s;


	printf("%.08Lf\n", ans);

	return 0;
}