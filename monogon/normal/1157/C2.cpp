
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
			if(a[l] < a[r]) {
				prev = a[l];
				l++;
				ss << "L";
			}else if(a[l] > a[r]) {
				prev = a[r];
				r--;
				ss << "R";
			}else {
				// a[l] == a[r]
				bool b = true; // true if we should choose left
				int i = 0;
				for(i = 1; l + i <= r; i++) {
					if(a[r - i] <= a[r - i + 1]) {
						b = true;
						break;
					}
					if(a[l + i] <= a[l + i - 1]) {
						b = false;
						break;
					}
				}
				if(b) {
					for(int j = 0; j < i && a[l] > prev; j++) {
						prev = a[l];
						l++;
						ss << "L";
					}
				}else {
					for(int j = 0; j < i && a[r] > prev; j++) {
						prev = a[r];
						r--;
						ss << "R";
					}
				}
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