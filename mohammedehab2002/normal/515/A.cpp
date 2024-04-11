#include <iostream>
using namespace std;
int abs(int x)
{
	return (x>0)? x:x*-1;
}
int main()
{
	int a,b,s;
	cin >> a >> b >> s;
	if (s>=abs(a)+abs(b) && (s-(abs(a)+abs(b)))%2==0)
	cout << "Yes";
	else
	cout << "No";
}