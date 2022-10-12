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
	int cnta = 0, cntb = 0;
	while(n--)
	{
		int a, b;
		cin >> a >> b;
		if(a == b) continue;
		(a > b) ? cnta++ : cntb++;
	}
	if(cnta > cntb) cout << "Mishka" << endl;
	else if(cntb > cnta) cout << "Chris" << endl;
	else cout << "Friendship is magic!^^" << endl;
}