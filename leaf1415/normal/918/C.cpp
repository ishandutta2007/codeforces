#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

using namespace std;

string s;
bool ok[2][5005][5005];

int main(void)
{
	cin >> s;
	
	int lb, rb, q;
	for(int l = 0; l < s.size(); l++){
		lb = rb = q = 0;
		for(int r = l; r < s.size(); r++){
			if(s[r] == '(') lb++;
			else if(s[r] == ')') rb++;
			else if(s[r] == '?'){
				q++;
				//if(rb + 1 > lb + q - 1) q--, lb++;
			}
			if(lb + q < rb) break;
			if(lb + q >= rb && lb < rb) q--, lb++;
			if( (r-l+1) % 2 ) continue;
			if(abs(lb - rb) <= q){
				ok[0][l][r] = true;
				//cout << l << " " << r << endl;
			}
		}
	}
	
	reverse(s.begin(), s.end());
	
	for(int l = 0; l < s.size(); l++){
		lb = rb = q = 0;
		for(int r = l; r < s.size(); r++){
			if(s[r] == ')') lb++;
			else if(s[r] == '(') rb++;
			else if(s[r] == '?'){
				q++;
				//if(rb + 1 > lb + q - 1) q--, lb++;
			}
			if(lb + q < rb) break;
			if(lb + q >= rb && lb < rb) q--, lb++;
			if( (r-l+1) % 2 ) continue;
			if(abs(lb - rb) <= q){
				ok[1][s.size()-r-1][s.size()-l-1] = true;
				//cout << s.size()-r-1 << " " << s.size()-l-1 << endl;
			}
		}
	}
	
	int ans = 0;
	for(int i = 0; i < s.size(); i++){
		for(int j = 0; j < s.size(); j++){
			if(j < i) continue;
			if(ok[0][i][j] && ok[1][i][j]) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}