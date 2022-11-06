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

	scanf("%d %d", &n,&m);

	for (int i = 0; i < n; i++){
		scanf("%d", &x);
		a.push_back(x);
	}
	for (int i = 0; i < m; i++){
		scanf("%d", &y);
		b.push_back(y);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	x = 0;
	y = 0;
	for (;x<n&&y<m;){
		if (a[x] < b[y])x++;
		else if (a[x]>b[y])y++;
		else {
			ans = a[x];
			break;
		}
	}
	if (ans == 0){
		if (a[0] < b[0])ans = a[0] * 10 + b[0];
		else ans = b[0] * 10 + a[0];
	}

	printf("%d\n", ans);

	return 0;
}