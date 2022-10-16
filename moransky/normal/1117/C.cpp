#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 100010; 
typedef long long LL;
int x, y, x2, y2, n, sum[N][2];
char s[N]; 
//x 
bool check(LL d){
	LL nx = x, ny = y;
	nx += (d / n) * sum[n][0] + sum[d % n][0];
	ny += (d / n) * sum[n][1] + sum[d % n][1];
	return abs(x2 - nx) + abs(y2 - ny) <= d;
}
int main(){
	scanf("%d%d%d%d%d%s", &x, &y, &x2, &y2, &n, s + 1);
	for(int i = 1; i <= n; i++){
		sum[i][1] += sum[i - 1][1] + (s[i] == 'U');
		sum[i][1] -= (s[i] == 'D');
		sum[i][0] -= (s[i] == 'L');
		sum[i][0] += sum[i - 1][0] + (s[i] == 'R');
	}
	if(!check(1e14)) puts("-1");
	else{
		LL l = 1, r = 1e14;
		while(l < r){
			LL mid = (l + r) >> 1;
			if(check(mid))r = mid;
			else l = mid + 1;
		}	
		printf("%lld\n", r);
	}
	
	
	return 0;
}