#include <iostream>
#include <string>

using namespace std;

string s, t;
string v = "aiueo";

int main(void)
{
	cin >> s >> t;
	for(int i = 0; i < s.size(); i++){
		for(int j = 0; j < v.size(); j++){
			if(s[i] == v[j]){
				s[i] = '1';
				goto end;
			}
		}
		s[i] = '0';
		end:;
	}
	for(int i = 0; i < t.size(); i++){
		for(int j = 0; j < v.size(); j++){
			if(t[i] == v[j]){
				t[i] = '1';
				goto end2;
			}
		}
		t[i] = '0';
		end2:;
	}
	
	if(s == t) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}