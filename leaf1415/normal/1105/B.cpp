#include <iostream>
#include <string>

using namespace std;

int n, k;
string s;

int main(void)
{
	cin >> n >> k;
	cin >> s;
	
	int ans = 0;
	for(int i = 0; i < 26; i++){
		int num = 0, cnt = 0;
		for(int j = 0; j < s.size(); j++){
			if(s[j]-'a' == i) cnt++;
			else cnt = 0;
			if(cnt == k){
				num++;
				cnt = 0;
			}
		}
		ans = max(ans, num);
	}
	cout << ans << endl;
	
	return 0;
}