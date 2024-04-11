#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	string s;
	cin >> s;
	int c = 0;
	while(c < s.size() && s[c] == 'a'){
		c++;
	}
	if(c == s.size()){
		for(int i = 0; i < s.size()-1; i++){
			printf("a");
		}
		printf("z");
		printf("\n");
		return 0;
	}
	while(c < s.size() && s[c] != 'a'){
		s[c]--;
		c++;
	}
	cout << s << endl;
}