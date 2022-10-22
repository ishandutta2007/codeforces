#include <iostream>
#include <string>
#include <algorithm>
#define rep(N) for(int i=0;i<N;i++) 
using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	while(n--)
	{
		string c,ans[9];
		int s=0,k=-1;
		cin>>c;
		if(c=="::") {cout<<"0000:0000:0000:0000:0000:0000:0000:0000\n";continue;}
		c="0000"+c;
//		int tt=c.size()-1;
//		for(;c[tt]!=':';tt--);
		if(c[c.size()-1]!=':') c+=":";
		rep(c.size())
		{
			if(c[i]==':' && c[i-1]!=':')
			{
				bool f=false;
				ans[s++]=c.substr(i-4,4);
//				cout<<ans[s-1]<<':';
				for(int j=3;j>=0;j--)
				{
					if(ans[s-1][j]==':') f=true;
					if(f) ans[s-1][j]='0';
				}
			}
			else if(c[i]==':' && c[i-1]==':')
			{
				k=s;
			}
		}
		int t=0;
//		cout<<endl;
		rep(s)
		{
			if(k==i)
			{
				if(ans[i]!="") s++;
				for(int j=0;j<=8-s;j++)
				{
					t++;
					cout<<"0000"<<(t==8?'\n':':');
				}
				t++;
				cout<<ans[i]<<(t==8?'\n':':');
			}
			else
			{
				t++;
				cout<<ans[i];
				if(t==8) cout<<endl;else if(t<8) cout<<':';
			}
		}
		if(c[c.size()-1]==':' && c[c.size()-2]==':')
		{
			while(8-t>0)
			{
				t++;
				cout<<"0000"<<(t==8?'\n':':');
			}
		}
	}
	return 0;
}