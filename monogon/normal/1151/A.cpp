
#include <iostream>

using namespace std;

int n;
string str;
string g = "ACTG";

int main() {
	cin >> n >> str;
	int M = 1000000;
	for(int i = 0; i < n - 3; i++) {
		int sum = 0;
		for(int j = 0; j < 4; j++) {
			sum += min(abs(str[i + j] - g[j]), min(1 + abs('Z' - str[i + j]) + abs(g[j] - 'A'),
					1 + abs('A' - str[i + j]) + abs(g[j] - 'Z')));
		}
		if(sum < M) M = sum;
	}
	cout << M << endl;
}