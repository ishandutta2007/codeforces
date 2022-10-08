
#include <iostream>
#include <string>

using namespace std;

int n;
string a;
int f[10];

int main() {
	cin >> n >> a;
	for(int i = 1; i <= 9; i++) {
		cin >> f[i];
	}
	int i = 0;
	for(i = 0; i < n; i++) {
		if(a[i] - '0' < f[a[i] - '0']) {
			break;
		}
	}
	int j = i;
	for(j = i; j < n; j++) {
		if(a[j] - '0' > f[a[j] - '0']) {
			break;
		}else {
			a[j] = f[a[j] - '0'] + '0';
		}
	}
	cout << a << endl;
}