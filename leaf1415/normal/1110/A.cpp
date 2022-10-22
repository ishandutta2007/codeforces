#include <iostream>

using namespace std;
int b, k;
int a[100005];

int main(void)
{
	cin >> b >> k;
	for(int i = 1; i <= k; i++) cin >> a[i];
	
	if(b % 2 == 0){
		if(a[k] % 2) cout << "odd" << endl;
		else cout << "even" << endl;
		return 0;
	}
	
	int sum = 0;
	for(int i = 1; i <= k; i++) sum += a[i];
	if(sum % 2) cout << "odd" << endl;
	else cout << "even" << endl;
	
	return 0;
}