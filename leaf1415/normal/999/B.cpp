#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string s;

int main(void)
{
	cin >> n;
	cin >> s;
	for(int i = 1; i <= n; i++){
		if(n % i == 0) reverse(s.begin(), s.begin()+i);
	}
	cout << s << endl;
	return 0;
}