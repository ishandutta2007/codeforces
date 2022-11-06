#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(void){
	int a[300000];
	vector<int>b;
	int c;
	int p;
	int q;
	int r;
	int s;
	int n;
	int m;
	int x, y,z;
	int v;
	scanf("%d %d", &n, &m);
	x = -2;
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		if (a[i] < 0){
			c++;
			if(x!=-2)b.push_back(i-x-1);
			x = i;
		}
	}
	if (c > m){
		printf("-1\n");
		return 0;
	}
	else{
		m = m - c;
		sort(b.begin(), b.end());
		s = 0;
		z = 0;
		for (int i = 0; i < c-1; i++){
			if (b[i] + s <= m){
				z = z + 2;
				s = s + b[i];
			}
		}
		if (s + n - x - 1 <= m)z++;
		printf("%d\n", 2 * c - z);
	}
	return 0;
}