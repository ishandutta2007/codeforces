#include <iostream>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;

llint n;
llint a[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint pans = 0, nans = 0, mul = 1, pcnt = 1, ncnt = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == 0){
			mul = 1, pcnt = 1, ncnt = 0;
			continue;
		}
		if(a[i] > 0) mul *= 1;
		if(a[i] < 0) mul *= -1;
		if(mul == 1){
			pans += pcnt, nans += ncnt;
			pcnt++;
		}
		else{
			pans += ncnt, nans += pcnt;
			ncnt++;
		}
	}
	cout << nans << " " << pans << endl;
	
	return 0;
}