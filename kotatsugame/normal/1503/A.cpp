#include<iostream>
#include<vector>
using namespace std;
int T,N;
string S;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>S;
		vector<int>id,jd;
		for(int i=0;i<N;i++)
		{
			if(S[i]=='0')id.push_back(i);
			else jd.push_back(i);
		}
		if(id.size()%2||S[0]=='0'||S[N-1]=='0')
		{
			cout<<"NO\n";
			continue;
		}
		string A(N,'0'),B(N,'0');
		for(int i=0;i<id.size();i+=2)
		{
			A[id[i]]='(';
			A[id[i+1]]=')';
			B[id[i]]=')';
			B[id[i+1]]='(';
		}
		for(int i=0;i<jd.size();i++)
		{
			A[jd[i]]=B[jd[i]]=i*2<jd.size()?'(':')';
		}
		{
			cout<<"YES\n"<<A<<"\n"<<B<<"\n";
		}
	}
}