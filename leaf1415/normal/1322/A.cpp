#include <iostream>
#include <string>
#define llint long long

using namespace std;

llint n;
string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s;
	
	llint h = 0, ans = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '('){
			if(h < 0) ans++;
			h++;
		}
		else{
			h--;
			if(h < 0) ans++;
		}
	}
	if(h != 0) ans = -1;
	cout<<ans<<endl;
	
	return 0;
}