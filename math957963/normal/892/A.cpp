#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<queue>
using namespace std;
#define f(i,n) for(int i=0;i<(int)n;i++)
#define MOD 1000000009

int main(void){
	vector<long long>a;
	long long s = 0;
	int n;
	long long x;

	scanf("%d", &n);

	f(i, n){
		scanf("%I64d", &x);
		s += x;
	}

	f(i, n){
		scanf("%I64d", &x);
		a.push_back(x);
	}
	sort(a.begin(), a.end(), greater<long long>());
		if (a[0] + a[1] >= s)printf("YES\n");
		else printf("NO\n");
	return 0;
}