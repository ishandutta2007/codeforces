#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll unsigned long long
int main() {
	string s;
	ll n;
	cin >> n;
	getline(cin,s);
	for (ll i = 0; i < n; i++) {
		//cin >> s;
		getline(cin,s);
		bool miao = false;
		bool lala = false;
		//cout << s << endl;
		if (s.length() < 5) {
			cout <<  "OMG>.< I don't know!" << endl;
		}
		else {
			if (s.substr(0,5) == "miao.") {
				miao = true;
			}
			if (s.substr(s.length()-5,5) == "lala.") {
				lala = true;
			}
			if (miao && lala) {
				cout <<  "OMG>.< I don't know!" << endl;
			}
			else if (!miao && !lala) {
				cout << "OMG>.< I don't know!" << endl;
			}
			else if (miao) {
				cout << "Rainbow's" << endl;
			}
			else if (lala) {
				cout << "Freda's" << endl;
			}
		}
	}
	return 0;
}