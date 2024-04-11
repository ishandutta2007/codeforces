#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int n;cin>>n;
		string a,b;
		cin>>a>>b;
		bool ok=true;
		for(int i=0;i<n;i++)
		{
			char l=a[i],r=b[i];
			if(l=='G')l='B';
			if(r=='G')r='B';
			if(l!=r)ok=false;
		}
		cout<<(ok?"YES\n":"NO\n");
	}
}