#include <iostream>
#include <string>
#define llint long long

using namespace std;

llint n;
llint a[1005][1005];

llint get(llint x)
{
	llint ub = 1e9+7, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(mid*mid <= x) lb = mid;
		else ub = mid;
	}
	return lb;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		llint x = a[i][(i+1)%n] * a[i][(i+2)%n] / a[(i+1)%n][(i+2)%n];
		cout << get(x) << " ";
	}
	cout << endl;
	return 0;
}