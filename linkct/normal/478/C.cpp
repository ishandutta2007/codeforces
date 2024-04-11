#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;

ll s[4];

int main(){
	cin >> s[1] >> s[2] >> s[3];
	sort(s + 1, s + 4);
	if((s[1] + s[2]) << 1 < s[3])
		cout << s[1] + s[2] << endl;
	else cout << (s[1] + s[2] + s[3]) / 3 << endl;
	return 0;
}