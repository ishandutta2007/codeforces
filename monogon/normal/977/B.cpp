
#include <iostream>
#include <string>

using namespace std;

string str;

int n;
int arr[26][26];
int best = 0;
int idx = 0;

int main() {
	cin >> n >> str;
	for (int i = 0; i < n - 1; ++i) {
		int x = ++arr[str[i] - 'A'][str[i + 1] - 'A'];
		if(x > best) {
			best = x;
			idx = i;
		}
	}
	cout << str[idx] << str[idx + 1] << endl;
}