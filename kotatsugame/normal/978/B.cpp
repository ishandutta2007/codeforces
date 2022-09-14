#include<iostream>
using namespace std;
int N;
string S;
main()
{
	cin>>N>>S;
	int ans=0;
	for(int i=0;i<N;)
	{
		if(S[i]!='x')i++;
		else
		{
			int j=i;
			while(j<N&&S[j]=='x')j++;
			if(j-i>=3)ans+=j-i-2;
			i=j;
		}
	}
	cout<<ans<<endl;
}