#include <iostream>
#include <string>

using namespace std;

string colors[] = {"purple", "green", "blue", "orange", "red", "yellow"};
string gems[] = {"Power", "Time", "Space", "Soul", "Reality", "Mind"};

int n;
string color;
bool exclude[6];

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> color;
		for(int j = 0; j < 6; j++) {
			if(colors[j] == color) {
				exclude[j] = true;
			}
		}
	}
	cout << 6 - n << endl;
	for(int i = 0; i < 6; i++) {
		if(!exclude[i]) {
			cout << gems[i] << endl;
		}
	}
}