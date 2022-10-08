#include <iostream>

using namespace std;

int n;
int count[100];
int a;
int most = 0;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a;
		count[a - 1]++;
		if(count[a - 1] > most) {
			most = count[a - 1];
		}
	}
	cout << most << endl;
}