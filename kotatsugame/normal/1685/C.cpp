#include<iostream>
using namespace std;
int T,N;
string s;
int S[2<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>s;
		S[0]=0;
		for(int i=0;i<s.size();i++)
		{
			S[i+1]=S[i]+(s[i]=='('?1:-1);
		}
		int nl=-1,nr=-1;
		int mxi=0;
		for(int i=0;i<=s.size();i++)
		{
			if(S[i]<0)
			{
				if(nl==-1)nl=i;
				nr=i;
			}
			if(S[mxi]<S[i])mxi=i;
		}
		if(nl==-1)
		{
			cout<<"0\n";
			continue;
		}
		int lmi=0,rmi=s.size();
		for(int i=0;i<nl;i++)if(S[lmi]<S[i])lmi=i;
		for(int i=nr+1;i<=s.size();i++)if(S[rmi]<S[i])rmi=i;
		if(S[lmi]+S[rmi]>=S[mxi])
		{
			cout<<"1\n";
			cout<<lmi+1<<" "<<rmi<<"\n";
		}
		else
		{
			cout<<"2\n";
			cout<<lmi+1<<" "<<mxi<<"\n";
			cout<<mxi+1<<" "<<rmi<<"\n";
		}
	}
}