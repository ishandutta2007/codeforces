
#include <iostream>
#include <sstream>

using namespace std;

int n;
int a[200000];

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int l = 0;
	int r = n - 1;
	int prev = 0;
	stringstream ss;
	while(l <= r) {
		if(a[l] > prev && a[r] > prev) {
			if(a[l] <= a[r]) {
				prev = a[l];
				l++;
				ss << "L";
			}else {
				prev = a[r];
				r--;
				ss << "R";
			}
		}else if(a[l] > prev) {
			prev = a[l];
			l++;
			ss << "L";
		}else if(a[r] > prev) {
			prev = a[r];
			r--;
			ss << "R";
		}else break;
	}
	string s = ss.str();
	cout << s.length() << endl << s << endl;
}