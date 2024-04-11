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
	
	int n;
	string s;
	cin >> n >> s;
	int one = 0, zero = 0;
	for (int i = 0; i < n; i++)
	{
		if(s[i] == 'n') one++;
		if(s[i] == 'z') zero++;
	}

	for (int i = 0; i < one; i++) cout << 1 << " ";
	for (int i = 0; i < zero; i++) cout << 0 << " ";
}