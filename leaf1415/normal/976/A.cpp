#include <iostream>
#include <string>

using namespace std;

int n;
string s;

int main(void)
{
	cin >> n;
	cin >> s;
	
	int cnt0 = 0, cnt1 = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '0') cnt0++;
		else cnt1++;
	}
	
	if(cnt1 > 0) cout << "1";
	for(int i = 0; i < cnt0; i++){
		cout << "0";
	}
	cout << endl;
	
	return 0;
}