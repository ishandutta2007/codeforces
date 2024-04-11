#include<bits/stdc++.h> 
#include<fstream>
using namespace std;
#define int long long

main () {
	int t;
	cin >> t;
	while(t--)
	{
		int x;
		cin >> x;
		if(x % 14 >= 1 && x % 14 <= 6 && x > 6)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
    return 0;
}