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
	int a[N];
	int b[N];
	vector<int>c1, c2;
	f(i, N){
		a[i] = 0;
		b[i] = 0;
	}
	int n, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	f(i, n){
		scanf("%d", &a[i]);
		if (i > 0)c1.push_back(a[i] - a[i - 1]);
	}
	f(i, n){
		scanf("%d", &b[i]);
		if (i > 0)c2.push_back(b[i] - b[i - 1]);
	}
	if (a[0] != b[0])v = false;
	if (a[n-1] != b[n-1])v = false;
	sort(c1.begin(), c1.end());
	sort(c2.begin(), c2.end());
	f(i, n - 1){
		if (c1[i] != c2[i])v = false;
	}

	if(v)printf("Yes\n");
	else printf("No\n");


	return 0;
}