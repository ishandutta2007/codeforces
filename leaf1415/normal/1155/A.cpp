#include <iostream>
#include <string>

using namespace std;

int n;
string s;

int main(void)
{
	cin >> n >> s;
	
	for(int i = 1; i < s.size(); i++){
		if(s[i-1] > s[i]){
			cout << "YES" << endl;
			cout << i << " " << i+1 << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	
	return 0;
}