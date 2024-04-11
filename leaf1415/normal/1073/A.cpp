#include <iostream>
#include <string>

using namespace std;

int n;
string s;

int main(void)
{
	cin >> n;
	cin >> s;
	
	for(int i = 0; i < (int)s.size()-1; i++){
		if(s[i] != s[i+1]){
			cout << "YES" << endl;
			cout << s[i] << s[i+1] << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	
	return 0;
}