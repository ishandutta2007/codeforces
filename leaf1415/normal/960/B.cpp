#include <iostream>
#include <queue>
#include <stdlib.h>
#define llint long long

using namespace std;

llint n, k1, k2;
llint a[1005], b[1005];
priority_queue<llint> Q;

int main(void)
{
	cin >> n >> k1 >> k2;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	
	for(int i = 1; i <= n; i++){
		Q.push(abs(a[i]-b[i]));
	}
	for(int i = 0; i < k1+k2;i++){
		llint x = Q.top();
		Q.pop();
		if(x == 0) x++;
		else x--;
		Q.push(x);
	}
	
	llint ans = 0;
	while(Q.size()){
		ans += Q.top() * Q.top();
		Q.pop();
	}
	cout << ans << endl;
	return 0;
}