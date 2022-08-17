#include <iostream>
#include <string>

using namespace std;
typedef long long ll;
int main()
{
    ll n,m,a, rez=0, R;
	cin>>n>>m>>a;
	rez = m/a;
	if (m%a) rez++;
	R = n/a;
	if (n%a) R++;
	cout<<rez*R;
	
}