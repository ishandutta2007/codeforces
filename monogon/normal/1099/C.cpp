
#include <iostream>
#include <string>

using namespace std;

string s;
int n, k;

int main() {
	cin >> s >> k;
	n = s.length();
	int mymin = n;
	int mymax = n;
	int mymax2 = n; //maximum if we only use question marks
	for(int i = 0; i < n; i++) {
		if(s[i] == '?') {
			mymin -= 2;
			if(mymax >= 0) {
				mymax--;
			}
			mymax2--;
		}else if(s[i] == '*') {
			mymin -= 2;
			mymax = -1;
			mymax2 -= 2;
		}
	}
	if(k < mymin || (k > mymax && mymax >= 0)) {
		cout << "Impossible" << endl;
		return 0;
	}
	int count = mymin;
	for(int i = 0; i < n; i++) {
		if(i < n - 1 && s[i + 1] == '?') {
			if(count < k) {
				cout << s[i];
				count++;
			}
			i++;
		}else if(i < n - 1 && s[i + 1] == '*') {
			while(count < k) {
				cout << s[i];
				count++;
			}
			i++;
		}else {
			cout << s[i];
		}
	}
}