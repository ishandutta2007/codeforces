#include <bits/stdc++.h>
using namespace std;

string S;

int main()
{
	cin >> S;
	int ans = 1, len = S.length();
	for (int i=1;i<len;i++) ans += (1<<i);
	for (char c: S){
		len--;
		if (c == '7') ans += (1<<len);
	}
	cout << ans << endl;
}