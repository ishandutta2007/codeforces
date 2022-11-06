#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
int main(void){
	vector<int>a,b;
	int c=0;
	int k, s;
	int n, m;
	int x, y, z;
	int ans=0;

	scanf("%d %d", &n,&k);

	for (int i = 0; i < n; i++){
		scanf("%d", &x);
		a.push_back(x);
		if (k == 2 && i == 0)y = x;
		if (k == 2 && i == n - 1)z = x;
	}
	sort(a.begin(), a.end());
	if (k == 1)ans = a[0];
	else if (k >= 3)ans = a[n - 1];
	else ans = max(y, z);

	printf("%d\n", ans);

	return 0;
}