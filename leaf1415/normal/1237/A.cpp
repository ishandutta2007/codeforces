#include <iostream>
#include <cstdlib>
#define llint long long

using namespace std;

llint n;
llint a[14005], b[14005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	llint ocnt = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(abs(a[i])%2) ocnt++;
	}
	ocnt /= 2;
	for(int i = 1;i <= n; i++){
		if(abs(a[i])%2==0) b[i] = a[i]/2;
		else{
			if(a[i] >= 0) b[i] = a[i]/2;
			else b[i] = -abs(a[i])/2-1;
			if(ocnt > 0) b[i]++, ocnt--;
		}
	}
	for(int i = 1; i <= n; i++) cout << b[i] << "\n";
	flush(cout);
	
	return 0;
}