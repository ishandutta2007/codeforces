#include <iostream>
#include <string>
#include <algorithm>
#define llint long long

using namespace std;

llint T;
llint a, b;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> a >> b;
		llint d = abs(a-b);
		llint sum = 0;
		for(llint i = 0; ; i++){
			sum += i;
			if(sum >= d && (sum-d)%2 == 0){
				cout << i << endl;
				break;
			}
		}
	}
	
	return 0;
}