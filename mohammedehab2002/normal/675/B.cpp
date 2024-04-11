#include <iostream>
using namespace std;
int main()
{
	int n,a,b,c,d,ma,mi;
	cin >> n >> a >> b >> c >> d;
	ma=max(a+c,max(c+d,max(d+b,b+a)));
	mi=min(a+c,min(c+d,min(d+b,b+a)));
	int ans=(ma+1)-mi;
	ans=n-ans+1;
	cout << max((long long)0,(long long)ans*n);
}