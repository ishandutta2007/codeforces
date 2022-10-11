#include <iostream>
using namespace std;
int main()
{
	long long a,b,c;
	cin >> a >> b >> c;
	long long ans=(a+b+c)/3;
	ans=min(ans,a+b);
	ans=min(ans,b+c);
	ans=min(ans,a+c);
	cout << ans;
}