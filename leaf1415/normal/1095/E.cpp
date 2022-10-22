#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string s;
int lv[1000005];
int r[1000005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s;
	if(n%2){
		cout << 0 << endl;
		return 0;
	}
	
	int h = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '(') h++;
		else h--;
	}
	if(h != 2 && h != -2){
		cout << 0 << endl;
		return 0;
	}
	if(h > 0){
		reverse(s.begin(), s.end());
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '(') s[i] = ')';
			else s[i] = '(';
		}
	}
	
	h = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '(') h++;
		else h--;
		lv[i] = h;
	}
	
	r[n-1] = lv[n-1];
	for(int i = n-2; i >= 0; i--){
		r[i] = min(r[i+1], lv[i]);
	}
	
	h = 0;
	int ans = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '(') h++;
		else{
			h--;
			if(r[i] >= -2) ans++;
		}
		if(h < 0) break;
	}
	cout << ans << endl;
	
	return 0;
}