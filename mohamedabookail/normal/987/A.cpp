/**
 *    author:  Mohamed.Abo_Okail
 *    created: 24/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"


int main()
{
	std::ios_base::sync_with_stdio(0);
	
	map <string, string> mp;
	mp["purple"] = "Power";
	mp["green"] = "Time";
	mp["blue"] = "Space";
	mp["orange"] = "Soul";
	mp["red"] = "Reality";
	mp["yellow"] = "Mind";

	int n; cin >> n;
	int m = n;
	while(m--)
	{
		string s; cin >> s;
		mp[s] = "^_^";
	}
	
	cout << 6 - n << endl;
	for(auto it = mp.cbegin(); it != mp.cend(); it++) {
		if(it->second != "^_^")
			cout << it-> second << endl;
	}

}