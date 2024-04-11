#include <iostream>
#include <string>

using namespace std;

int q, n;
string s;

int main(void)
{
	cin >> q;
	for(int i = 0; i < q; i++){
		cin >> n;
		cin >> s;
		if(s.size() == 2 && s[0] >= s[1]){
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		cout << 2 << endl;
		cout << s[0] << " " << s.substr(1) << endl;
	}
	
	return 0;
}