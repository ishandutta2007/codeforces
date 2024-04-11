#include <iostream>
#include <string>

using namespace std;

int n;
string s[3];
int cnt[3][256];
int num[3];
int ans[3];
string name[] = {"Kuro", "Shiro" , "Katie"};

int main(void)
{
	cin >> n;
	for(int i = 0; i < 3; i++) cin >> s[i];
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < s[i].size(); j++){
			cnt[i][s[i][j]]++;
		}
	}
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 256; j++){
			num[i] = max(num[i], cnt[i][j]);
		}
	}
	for(int i = 0; i < 3; i++){
		if(n == 1 && num[i] == s[i].size()) ans[i] = s[i].size()-1;
		else ans[i] = min(num[i] + n, (int)s[i].size());
	}
	
	int max_val = 0, max_i;
	for(int i = 0; i < 3; i++){
		if(max_val < ans[i]){
			max_i = i;
			max_val = ans[i];
		}
	}
	int maxn = 0;
	for(int i = 0; i < 3; i++) if(ans[i] == max_val) maxn++;
	if(maxn >= 2) cout << "Draw" << endl;
	else cout << name[max_i] << endl;
	
	return 0;
}