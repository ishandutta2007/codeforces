#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int t; cin>>t;
	while(t--)
	{
		string a,b; cin>>a>>b;
		int n1 = a.size();
		int n2 = b.size();
		int yin = __gcd(n1,n2);
		string a1,a2;
		for(int i=1;i<=n2/yin;i++) a1+=a;
		for(int i=1;i<=n1/yin;i++) a2+=b;
		if(a1==a2) cout<<a1<<endl;
		else cout<<-1<<endl;
		

	}
}