#include <iostream>
#include <string>
#define llint long long
#define mod 998244353

using namespace std;

llint n;
string s;

int main(void)
{
	cin >> n;
	cin >> s;
	
	llint l, r;
	for(int i = 0; i < n; i++){
		if(s[i] != s[0]){
			l = i;
			break;
		}
	}
	for(int i = 0; i < n; i++){
		if(s[n-1-i] != s[n-1]){
			r = i;
			break;
		}
	}
	
	if(s[0] != s[n-1]){
		cout << l+r+1 << endl;
	}else{
		cout << (l+1)*(r+1)%mod << endl;
	}
	
	return 0;
}