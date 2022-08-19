#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	LL n, x, y;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	LL num = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '0' && (i == 0 || (i > 0 && s[i-1] != '0'))){
			num++;
		}
	}
	if(num == 0){
		cout << 0 << '\n';
	} else {
		cout << y + (num - 1) * min(x,y) << '\n';
	}
}