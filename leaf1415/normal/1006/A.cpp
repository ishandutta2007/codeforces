#include <iostream>

using namespace std;

int n;
int a[1005];

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++){
		a[i] = (a[i]+1)/2*2-1;
	}
	for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
	return 0;
}