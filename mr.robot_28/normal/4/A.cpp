#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>
#include<set>
#include<stack>
#include<string>
using namespace std;
int main()
{
	int w;
	cin >> w;
	if(w % 2 == 0 && w > 2)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}