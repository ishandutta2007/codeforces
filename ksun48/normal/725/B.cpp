#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	string a;
	cin >> a;
	int d = a[a.size()-1] - 'a';
	LL b = 0;
	for(int i = 0; i < a.size() - 1; i++){
		b *= 10;
		b += a[i]-'0';
	}
	LL ans = 0;
	if(b % 2 == 0){
		ans += 7;
		b--;
	}
	b--;
	b /= 4;
	ans += b*16;
	if(d >= 3){
		ans += (6-d);
	} else {
		ans += (d+4);
	}
	cout << ans << endl;
}