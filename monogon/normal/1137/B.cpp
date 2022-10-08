
#include <iostream>

using namespace std;

string s, t;
int n, N[2];
int kmp[500000];

void computeKMP(string str, int *kmp) {
	int len = 0;
	kmp[0] = 0;
	for(unsigned int i = 1; i < str.length(); i++) {
		if(str[i] == str[len]) {
			len++;
			kmp[i] = len;
		}else if(len != 0) {
			len = kmp[len - 1];
			i--;
		}else {
			kmp[i] = 0;
		}
	}
}

int main() {
	cin >> s >> t;
	n = s.length();
	for(int i = 0; i < n; i++) {
		N[s[i] - '0']++;
	}
	computeKMP(t, kmp);
	int k = kmp[t.length() - 1];
	int j = 0; // index in t
	for(int i = 0; i < n; i++) {
		if(N[t[j] - '0'] > 0) {
			s[i] = t[j];
			N[t[j] - '0']--;
			j++;
		}else {
			s[i] = '0' + ((t[j] - '0' + 1) % 2);
			N[s[i] - '0']--;
			j = 0;
		}
		if(j == t.length()) {
			j = k;
		}
	}
	cout << s << endl;
}