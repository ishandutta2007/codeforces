#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	if(s.substr(0) < s.substr(k)){
		int i = k-1;
		while(s[i] == '9'){
			s[i] = '0';
			i--;
		}
		s[i]++;
	}
	cout << n << '\n';
	for(int i = 0; i < n; i++){
		cout << s[i % k];
	}
	cout << '\n';
}