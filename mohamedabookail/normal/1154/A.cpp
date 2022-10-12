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
	
	int arr[4];
	for (int i = 0; i < 4; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + 4);
	for (int i = 0; i < 3; i++)
	{
		cout << arr[3] - arr[i] << " ";
	}
}