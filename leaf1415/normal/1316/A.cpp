#include <iostream>
#define llint long long

using namespace std;

llint T;
llint n, m;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> m;
		llint sum = 0, a;
		for(int i = 1; i <= n; i++){
			cin >> a;
			sum += a;
		}
		cout << min(sum, m) << endl;
	}
	
	return 0;
}