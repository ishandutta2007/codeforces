#include <iostream>
#include <algorithm>

using namespace std;

int T;
int n;
string s, ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		cin >> s;
		
		for(int i = 0; i < 10; i++){
			int l = 0, u = i; bool flag = true; ans = "";
			for(int j = 0; j < s.size(); j++){
				int x = s[j]-'0';
				if(x >= u) u = x, ans += "2";
				else if(x >= l) l = x, ans += "1";
				else{
					flag = false;
					break;
				}
			}
			if(l > i) flag = false;
			if(flag){
				cout << ans << endl;
				goto end;
			}
		}
		cout << "-" << "\n";
		end:;
	}
	flush(cout);
	
	return 0;
}