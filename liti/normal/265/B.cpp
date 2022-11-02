#include <iostream>
#include <cmath>
using namespace std;

int main(){
	long n;
	cin >> n;
	int a[100001];
	long result;
	a[0] = 1;
	for(int i =1 ; i <= n; i++){
		cin >> a[i];
		result += abs(a[i]-a[i-1]) + 2;
	}
	cout << result << endl;
}