#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	/*LL n, b, d, cur = 0, c;
	cin >> n >> b >> d;
	for(int i = 0; i < n; i++){
		cin >> c;
		if(c <= b) cur += c;
	}
	cout << (cur-1)/d << endl;*/
	int n, a;
	cin >> n >> a;
	int s[n];
	for(int i = 0; i < n; i++) cin >> s[i];
	if(n == 1){
		cout << 0 << endl;
		return 0;
	}
	sort(s,s+n);
	cout << min(min(abs(a-s[0])+abs(s[0]-s[n-2]),abs(a-s[n-2])+abs(s[0]-s[n-2])),
				min(abs(a-s[1])+abs(s[1]-s[n-1]),abs(a-s[n-1])+abs(s[1]-s[n-1]))) << endl;
}