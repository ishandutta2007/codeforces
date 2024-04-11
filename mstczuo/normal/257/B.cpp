# include <iostream>
# include <cstdio>
using namespace std;

int n,m;
int main()
{
	cin >> n >> m;
	cout << max(n,m)-1 << ' ' << min(m,n);
}