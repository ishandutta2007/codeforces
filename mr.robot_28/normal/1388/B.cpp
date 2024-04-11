#include<bits/stdc++.h>
 
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			if((n - i - 1) * 4 < n)
			{
				cout << 8;
			}
			else
			{
				cout << 9;
			}	
		}
		cout << "\n";
	}
	return 0;
}