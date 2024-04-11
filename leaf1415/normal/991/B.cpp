#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[105];

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	
	int need = (9*n+1) / 2;
	int sum = 0;
	for(int i = 0; i < n; i++) sum += a[i];
	if(sum >= need){
		cout << 0 << endl;
		return 0;
	}
	for(int i = 0; i < n; i++){
		sum += 5 - a[i];
		if(sum >= need){
			cout << i+1 << endl;
			return 0;
		}
	}
	return 0;
}