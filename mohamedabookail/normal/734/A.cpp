/**
 *    author:  Mohamed.Abo_Okail
 *    created: 27/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	
	int n; cin >> n;
	string s; cin >> s;
	int a = 0, d = 0;
	for (int i = 0; i < n; i++)
	{
		(s[i] == 'A') ? a++ : d++;
	}

	if(a > d) cout << "Anton" << endl;
	else if(d > a) cout << "Danik" << endl;
	else cout << "Friendship" << endl;
}