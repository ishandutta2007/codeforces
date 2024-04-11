/**
 *    author:  Mohamed.Abo_Okail
 *    created: 05/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	//freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
	
	int n; cin >> n;
	cout << "I hate "; n--;
	int f = 1;
	for (int i = 0; i < n; i++)
	{
		if(f == 1)
			cout << "that I love ";
		else
			cout << "that I hate ";
		f *= -1;
	}
	cout << "it" << endl;
	
}