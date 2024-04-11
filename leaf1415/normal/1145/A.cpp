#include <iostream>

using namespace std;

int n;
int a[20];

int calc(int l, int r)
{
	if(l == r) return 1;
	bool flag = true;
	for(int i = l; i < r; i++){
		if(a[i] > a[i+1]) flag = false;
	}
	if(flag) return r-l+1;
	return max(calc(l, (l+r)/2), calc((l+r)/2+1, r));
}

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	cout << calc(0, n-1) << endl;
	return 0;
}