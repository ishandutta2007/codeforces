
#include <iostream>
#include <vector>

using namespace std;

int n;
string str;
bool b[100000];
vector<int> d1, d2;

int main() {
	cin >> n >> str;
	for(int i = 0; i < n; i++) {
		if(str[i] == '8') {
			d1.push_back(i);
		}else {
			d2.push_back(i);
		}
	}
	unsigned int i = 0;
	unsigned int j = 0;
	for(int t = n; t > 11; t--) {
		// Vasya wants 8's
		if(j == d2.size()) {
			d1.pop_back();
		}else {
			j++;
		}
		t--;

		// Petya doesn't like 8's
		if(t > 11) {
			i++;
			if(i >= d1.size()) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	if(j < d2.size() && d2[j] < d1[i]) {
		cout << "NO" << endl;
	}else {
		cout << "YES" << endl;
	}
}