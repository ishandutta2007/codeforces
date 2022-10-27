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
		if(n - 30 == 6)
		{
			cout << "YES\n";
			cout << 5 << " " << 6 << " " << 10 << " " << 15 << "\n";
		}
		else if(n - 30 == 10){
			cout << "YES\n";
			cout << 6 << " " << 14 << " " << 5<< " " << 15 << "\n";
		}
		else if(n - 30 == 14)
		{
			cout << "YES\n";
			cout << 6 << " " << 10 << " " << 7 << " " << 21 << "\n";
		}
		else if(n > 30)
		{
			cout << "YES\n";
			cout << 6 << " " << 10 << " " << 14 << " " << n - 30 << "\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}