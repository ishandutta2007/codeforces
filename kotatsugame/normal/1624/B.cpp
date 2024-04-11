#include<iostream>
using namespace std;
int T;
int a,b,c;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>a>>b>>c;
		bool fn=false;
		{
			int d=b-a;
			int nc=b+d;
			if(nc%c==0&&nc/c>=1)fn=true;
		}
		{
			int d=c-a;
			if(d%2==0)
			{
				int nb=a+d/2;
				if(nb%b==0&&nb/b>=1)fn=true;
			}
		}
		{
			int d=c-b;
			int na=b-d;
			if(na%a==0&&na/a>=1)fn=true;
		}
		cout<<(fn?"YES\n":"NO\n");
	}
}