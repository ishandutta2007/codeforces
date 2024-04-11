#include <iostream>
using namespace std;
int main()
{
	int n,m,i=1;
	cin >> n >> m;
	while (m>=i)
	{
		m-=i;
		i++;
		if (i==n+1)
		i=1;
	}
	cout << m;
}