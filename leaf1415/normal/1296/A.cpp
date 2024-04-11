#include <iostream>
#define llint long long

using namespace std;

llint T, n;
llint a[2005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		llint sum = 0; bool oflag = false, eflag = false;
		for(int i = 1; i <= n; i++){
			sum += a[i];
			if(a[i] % 2) eflag = true;
			else oflag = true;
		}
		if(sum % 2 || (oflag && eflag)) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	flush(cout);
	
	return 0;
}