#include <bits/stdc++.h>
using namespace std;
int n, x, sg[80] =
{
	0,
	1,1,
	2,2,2,
	3,3,3,3,
	4,4,4,4,4,
	5,5,5,5,5,5,
	6,6,6,6,6,6,6,
	7,7,7,7,7,7,7,7,
	8,8,8,8,8,8,8,8,8,
	9,9,9,9,9,9,9,9,9,9,
	10,10,10,10,10,10,10,10,10,10,10,11
};
int main()
{
	cin >> n;
	int ans=0;
	for(int i = 1; i <= n; i ++)
	{
		cin >> x;
		ans=ans^sg[x];
	}
	if(ans) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	return 0;
}