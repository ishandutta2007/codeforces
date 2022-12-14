#include<bits/stdc++.h>
using namespace std;
int n;
void fc()
{
	cin>>n;
	cout<<1<<" "<<n<<" ";
	for (int i=2;i<=n-1;i++) cout<<i<<" ";
	cout<<'\n';
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int T=1;
	cin>>T;
	while (T--)
	{
		fc();
	}
}