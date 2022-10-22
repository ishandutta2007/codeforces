#include <iostream>
#include <string>

using namespace std;

string s;

int main(void)
{
	cin >> s;
	
	char next = 'a';
	for(int i = 0; i < s.size(); i++){
		if(s[i] <= next){
			s[i] = next++;
		}
		if(next > 'z'){
			cout << s << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}