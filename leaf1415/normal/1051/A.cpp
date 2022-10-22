#include <iostream>
#include <string>

using namespace std;

int T;
string s;

int main(void)
{
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> s;
		
		int n[3] = {0, 0, 0};
		for(int i = 0; i < s.size(); i++){
			if(s[i] >= 'A' && s[i] <= 'Z') n[0]++;
			if(s[i] >= 'a' && s[i] <= 'z') n[1]++;
			if(s[i] >= '0' && s[i] <= '9') n[2]++;
		}
		int cnt = 0;
		for(int i = 0; i < 3; i++) if(n[i]) cnt++;
		
		if(cnt == 3){
			cout << s << endl;
			continue;
		}
		if(cnt == 1){
			if(n[0]) s[0] = 'a', s[1] = '1'; 
			if(n[1]) s[0] = 'A', s[1] = '1'; 
			if(n[2]) s[0] = 'A', s[1] = 'a'; 
			cout << s << endl;
			continue;
		}
		int less, many;
		for(int i = 0; i < 3; i++){
			if(n[i] == 0) less = i;
			if(n[i] >= 2) many = i;
		}
		for(int i = 0; i < s.size(); i++){
			if(many == 0 && s[i] >= 'A' && s[i] <= 'Z' || 
				many == 1 && s[i] >= 'a' && s[i] <= 'z' || 
				many == 2 && s[i] >= '0' && s[i] <= '9') {
					if(less == 0) s[i] = 'A';
					if(less == 1) s[i] = 'a';
					if(less == 2) s[i] = '0';
					break;
				}
		}
		cout << s << endl;
	}
	return 0;
}