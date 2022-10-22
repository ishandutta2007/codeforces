#include <iostream>
#include <string>

using namespace std;

int n;
string s;

int main(void)
{
	cin >> n;
	cin >> s;
	
	int p = 0;
	for(int i = 1; ; i++){
		if(p >= n) break;
		cout << s[p];
		p += i;
	}
	cout << endl;
	return 0;
}