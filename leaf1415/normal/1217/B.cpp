#include <iostream>
#define llint long long

using namespace std;

llint T;
llint n, x;
llint d[105], h[105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> x;
		for(int i = 0; i < n; i++) cin >> d[i] >> h[i];
		
		llint maxa = -1, maxd = -1;
		for(int i = 0; i < n; i++){
			maxa = max(maxa, d[i]-h[i]);
			maxd = max(maxd, d[i]);
		}
		if(x <= maxd){
			cout << 1 << endl;
			continue;
		}
		if(maxa <= 0){
			cout << -1 << endl;
			continue;
		}
		cout << (x-maxd+maxa-1)/maxa + 1 << endl;
	}
	return 0;
}