#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#define llint long long

using namespace std;

llint T;
llint n, k;
llint d[105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> k;
		
		if(k % 3){
			if(n % 3 == 0) cout << "Bob" << endl;
			else cout << "Alice" << endl;
			continue;
		}
		if(n % (k+1) % 3 == 0 && n % (k+1) != k) cout << "Bob" << endl;
		else cout << "Alice" << endl;
	}
	
	return 0;
}