#include <iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	int ans=0;
	for (int i=0;i<=min(3,min(min(a,b),c));i++)
	ans=max(ans,(a-i)/3+(b-i)/3+(c-i)/3+i);
	cout << ans;
}