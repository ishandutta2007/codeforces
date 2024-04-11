#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,cnt=1;
	cin >> n;
	int ans=n-1;
	n--;
	while (n)
	{
		ans+=cnt*n;
		cnt++;
		n--;
	}
	cout << ans+1;
}