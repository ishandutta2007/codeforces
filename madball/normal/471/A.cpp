#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	int count[10];
	for (int i = 0; i < 10; i++)
		count[i] = 0;
	int cur;
	for (int i = 0; i < 6; i++) {
		cin >> cur;
		count[cur]++;
	}
	bool has2 = false, has4 = false;
	for (int i = 0; i < 10; i++) {
		if (count[i] >= 4) {
			has4 = true;
			count[i] -= 4;
		}
		if (count[i] >= 2) {
			has2 = true;
			count[i] -= 2;
		}
	}
	if (has4)
		cout << (has2 ? "Elephant" : "Bear");
	else
		cout << "Alien";
	return 0;
}