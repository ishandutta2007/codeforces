#include <iostream>
using namespace std;
int main()
{
	int t,s,q,ans=0;
	cin >> t >> s >> q;
	do{
		s*=q;
		ans++;
	}while (s<t);
	cout << ans;
}