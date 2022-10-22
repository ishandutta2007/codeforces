#include <iostream>
#include <string>
#define llint long long

using namespace std;

llint n, x, y;
string s;

int main(void)
{
	cin >> n >> x >> y;
	cin >> s;
	
	llint cnt = 0;
	char prev = '1';
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '0'){
			if(prev == '1') cnt++;
		}
		prev = s[i];
	}
	
	if(cnt == 0){
		cout << 0 << endl;
		return 0;
	}
	
	if(x < y){
		cout << (cnt-1)*x + y << endl;
	}
	else{
		cout << cnt*y << endl;
	}
	return 0;
}