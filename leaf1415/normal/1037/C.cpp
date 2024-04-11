#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int n;
string s, t;
string a;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	cin >> s >> t;
	
	for(int i = 0; i < n; i++){
		if(s[i] == t[i]) a += "*";
		else a += s[i];
	}
	
	int ans = 0; char pre = '*';
	for(int i = 0; i < n; i++){
		if(a[i] == '0' && pre == '1'){
			pre = '*';
		}
		else if(a[i] == '1' && pre == '0'){
			pre = '*';
		}
		else{
			if(a[i] != '*') ans++;
			pre = a[i];
		}
	}
	cout << ans << endl;
	return 0;
}