#include<bits/stdc++.h>
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++)
    {
    	if(s[i] != 'o')
    	{
    		cout << s[i];
    		continue;
		}
    	int j = i;
    	while(j < n - 2 && s[j + 1] == 'g' && s[j + 2] == 'o')
    	{
    		j += 2;
		}
		if(j == i)
		{
			cout << s[i];
			continue;
		}
		cout << "***";
		i = j;
	}
    return 0;
}