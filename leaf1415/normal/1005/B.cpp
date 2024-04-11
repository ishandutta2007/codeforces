#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s, t;

int main(void)
{
	cin >> s >> t;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	
	int com = 0;
	for(int i = 0; i < min(s.size(), t.size()); i++){
		if(s[i] != t[i]) break;
		com++;
	}
	
	cout << s.size()+t.size() - 2*com << endl;
	return 0;
}