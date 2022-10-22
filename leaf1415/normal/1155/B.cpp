#include <iostream>
#include <string>

using namespace std;

int n;
string s;

int main(void)
{
	cin >> n >> s;
	
	int turn = (n-11)/2, cnt = 0, cnt8 = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '8') cnt8++;
		else cnt++;
		if(cnt8 > turn){
			if(cnt <= turn) cout << "YES" << endl;
			else cout << "NO" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	
	return 0;
}