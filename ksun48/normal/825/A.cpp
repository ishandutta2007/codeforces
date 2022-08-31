#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cur = 0;
	int num = 0;
	s += '0';
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '1'){
			cur++;
		} else {
			num *= 10;
			num += cur;
			cur = 0;
		}
	}
	cout << num << endl;
}