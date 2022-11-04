#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;char c;
	string res;
	string k = "qwertyuiopasdfghjkl;zxcvbnm,./";
	cin >> c >> s;
	int a = (c == 'R' ? -1 : 1);
	for(int i=0; i< s.size(); i++){
		int aux = k.find(s[i]);
		res += k[aux + a];
	}
	cout << res;
	
}