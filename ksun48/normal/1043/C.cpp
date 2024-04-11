#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	string s;
	cin >> s;
	string t = s;
	sort(t.begin(), t.end());
	int n = s.size();
	vector<int> f(n);
	for(int i = n-1; i >= 0; i--){
		if(t[i] != s[i]){
			reverse(t.begin(), t.begin() + (i+1));
			f[i] = 1;
		} else {
			f[i] = 0;
		}
	}
	for(int i = 0; i < n; i++){
		cout << f[i] << " ";
	}
	cout << endl;
}