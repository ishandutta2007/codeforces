#include <iostream>
#include <stdio.h>
#define llint long long

using namespace std;

llint n, m;
llint x[100005], d[100005];

int main(void)
{
	cin >> n >> m;
	for(int i = 0; i < m; i++) cin >> x[i] >> d[i];
	
	llint ans = 0;
	for(int i = 0; i < m; i++){
		ans += x[i]*n;
		if(d[i] >= 0) ans += n*(n-1)/2*d[i];
		else{
			if(n % 2) ans += n/2*(n/2+1)*d[i];
			else ans += n/2*(n/2+1)/2*d[i] + n/2*(n/2-1)/2*d[i];
		}
	}
	printf("%.11f\n", (double)ans / n);
	return 0;
}