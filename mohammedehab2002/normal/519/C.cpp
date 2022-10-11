#include <iostream>
using namespace std;
int main()
{
	int n,m,ans=0;
	cin >> n >> m;
	if (n<m)
	swap(n,m);
	while (n>1 && m)
	{
		n-=2;
		m--;
		ans++;
		if (n<m)
		swap(n,m);
	}
	cout << ans;
}