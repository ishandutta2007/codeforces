#include <iostream>
#include <string>
#define llint long long
#define mod 1000000007
#define TH 10000000

using namespace std;

llint T;
llint x;
string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> x;
		cin >> s;
		
		llint ans = s.size(), len = s.size();
		for(int i = 0; i < x; i++){
			llint c = s[i]-'0', e = min(len, x);
			ans += (ans-(i+1)+mod) * (c-1) % mod, ans %= mod;
			if(len < TH){
				len += (len-i-1)*(c-1);
				if(len >= TH) len = TH;
			}
			for(int j = 0; j < c-1; j++){
				for(int k = i+1; k < e; k++){
					s += s[k];
					if(s.size() >= x) goto end;
				}
			}
			end:;
			//cout << s << " " << len << endl;
		}
		cout << ans << endl;
	}
	
	return 0;
}