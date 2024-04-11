#include <iostream>
#include <string>

using namespace std;
typedef long long ll;
int main()
{
    ll n,i=1;
cin>>n;
while (1)
{
if (!n) {cout<<"YES"; return 0;}
if (n>=i) n-=i;
else {cout<<"NO"; return 0;}
i++;
}
	
}