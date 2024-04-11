#include <iostream>
#define llint long long

using namespace std;

llint n, m;

int main(void)
{
	cin >> n >> m;
	cout << max(n-2*m, 0LL) << " ";
	if(m == 0){
		cout << n << endl;
		return 0;
	}
	for(llint i = 1; i <= n; i++){
		if(m <= i*(i-1)/2){
			cout << n-i << endl;
			return 0;
		}
	}
	return 0;
}