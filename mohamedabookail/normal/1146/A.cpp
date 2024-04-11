/**
 *    author:  Mohamed.Abo_Okail
 *    created: 30/10/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"
 
int main()
{
	std::ios_base::sync_with_stdio(0);
	//freopen("distinct.in", "r", stdin);
	//freopen("out.out", "w", stdout);
	
	string s; cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if(s[i] == 'a') cnt++;
	}
	if(cnt > (s.size() / 2))
	    cout << s.size() << endl;
	else 
		cout << cnt + cnt - 1 << endl;
}