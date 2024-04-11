#include <iostream>
#define llint long long

using  namespace std;

llint n, k;

int main(void)
{
	cin >> n >> k;
	
	for(llint i = 1; i <= k; i++){
		if(n % i != i-1){
			cout << "No" << endl;
			return 0;
		}
	}
	
	cout << "Yes" << endl;
	return 0;
}