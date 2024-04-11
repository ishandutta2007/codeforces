#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#define llint long long
#define mod 998244353

using namespace std;

string s;
string a, b;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	int n = s.size();
	if(s.size() <= 3){
		cout << s[0] << endl;
		return 0;
	}
	int l = 0, r = n-2;
	while(1){
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				if(s[l+i] == s[r+j]){
					a += s[l+i], b += s[r+j];
					goto end;
				}
			}
		}
		end:;
		if(r-(l+2) <= 3){
			if(r-(l+2) > 0) a += s[l+2];
			break;
		}
		l += 2, r -= 2;
	}
	reverse(b.begin(), b.end());
	cout << a + b << endl;
	
	return 0;
}