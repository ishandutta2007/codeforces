#include <iostream>
#include <string>

using namespace std;

int n;
string s;

int main(void)
{
	cin >> n;
	cin >> s;
	if(n%2){
		cout << ":(" << endl; //)
		return 0;
	}
	
	int lcnt = 0, rcnt = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '(') lcnt++;
		if(s[i] == ')') rcnt++;
	}
	if(lcnt > n/2){
		cout << ":(" << endl; //);
		return 0;
	}
	int rem = n/2 - lcnt, h = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '(') h++;
		if(s[i] == ')') h--;
		if(s[i] == '?'){
			if(rem > 0) h++, rem--, s[i] = '('; //)
			else h--, s[i] = ')';
		}
		if(i < n-1 && h <= 0){
			cout << ":(" << endl;
			return 0;
		}
	}
	cout << s << endl;
	return 0;
}