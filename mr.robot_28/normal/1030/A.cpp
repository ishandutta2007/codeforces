#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;
int main()
{
	int n, a;
	cin >> n;
	bool d = true;
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		if(a == 1)
		{
			d = false;
		}
	}
	if(d)
	{
		cout << "EASY";
	}
	else
	{
		cout << "HARD";
	}
	return 0;	
}