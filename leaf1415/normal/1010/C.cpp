#include <iostream>

using namespace std;

int n, k;
int a[100005];

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(void)
{
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	int d = k;
	for(int i = 0; i < n; i++) d = gcd(d, a[i]);
	cout << k / d << endl;
	for(int i = 0; d*i < k; i++) cout << d*i << " "; cout << endl;
	return 0;
}