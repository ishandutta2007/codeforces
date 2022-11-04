#include <iostream>

using namespace std;

int main(){
	int n, x, m, a[100005];
	long long vas=0,pet=0;

	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> x;
		a[x] = i;
	}

	cin >> m;
	while( m-- ){
		cin >> x;
		vas += a[x];
		pet += n - a[x] + 1;
	}

	cout << vas << " " << pet;

	return 0;
}