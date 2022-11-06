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






int main() {
	vector<int>a;
	int n, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	f(i, n) {
		scanf("%d", &x);
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	k = 0;
	f(i, n) {
		if (a[i] == a[0])k++;
	}
	k *= 2;
	k -= 2;

	if(k<n)printf("Alice\n");
	else  printf("Bob\n");


	return 0;
}