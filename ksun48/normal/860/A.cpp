#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	string f;
	cin >> f;
	string c;
	for(int i = 0; i < f.size(); i++){
		if(f[i] == 'a' || f[i] == 'e' || f[i] == 'i' || f[i] == 'o' || f[i] == 'u'){
			c += 'v';
		} else {
			c += 'c';
		}
	}
	string ans;
	int nc = 0;
	char last = '1';
	char same = 1;
	for(int i = 0; i < f.size(); i++){
		if(c[i] == 'v'){
			ans += f[i];
			nc = 0;
			last = '1';
			same = 1;
		} else {
			nc++;
			if(last == '1'){
				last = f[i];
			}
			if(last != f[i]){
				same = 0;
			}
			if(nc >= 3 && same == 0){
				ans += ' ';
				last = f[i];
				nc = 1;
				same = 1;
			}
			ans += f[i];
		}
	}
	cout << ans << endl;

}