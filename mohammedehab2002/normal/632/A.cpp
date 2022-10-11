#include <iostream>
using namespace std;
bool arr[45];
int main()
{
	int n,p;
	cin >> n >> p;
	for (int i=0;i<n;i++)
	{
		string s;
		cin >> s;
		arr[i]=((int)s.size()-4);
	}
	long long ans=0,a=0;
	for (int i=n-1;i>=0;i--)
	{
		a*=2;
		if (arr[i])
		a++;
		ans+=(a/2)*p+(a%2)*(p/2);
	}
	cout << ans;
}