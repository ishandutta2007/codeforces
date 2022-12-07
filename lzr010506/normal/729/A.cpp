#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
	cin >> n;
	cin >> s;
	int k = 0;
	while(k < n)
	{
		if(s[k] == 'o')
		{
			int r = k + 1;
			while(r < n)
			{
				if((r - k) % 2 == 1 && s[r] == 'g') r ++;
				else if((r - k) % 2 == 0 && s[r] == 'o') r ++;
				else break;
			}
			if(s[r - 1] == 'g') r --;
			if(r - k >= 3) cout << "***", k = r;
			else cout << s[k], k ++;
		} 
		else cout << s[k], k ++;
	}

	return 0;
}