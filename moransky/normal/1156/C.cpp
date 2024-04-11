#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200010;
int n, z, x[N];
bool check(int m){
	for(int i = 1; i <= m; i++)
		if(x[n - m + i] - x[i] < z) return false;
	return true;
}
int main(){
	scanf("%d%d", &n, &z);
	for(int i = 1; i <= n; i++)
		scanf("%d", x + i);
	sort(x + 1, x + 1 + n);
	int l = 0, r = n / 2;
	while(l < r){
		int mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
	return 0;
}