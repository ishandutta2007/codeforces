#include<iostream>
#include<vector>
using namespace std;
int T,N,K;
long long X;
string S;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>K>>X>>S;
		vector<int>A;
		for(int i=0;i<N;)
		{
			if(S[i]=='a')
			{
				A.push_back(-1);
				i++;
			}
			else
			{
				int c=0;
				while(i<N&&S[i]=='*')i++,c+=K;
				A.push_back(c);
			}
		}
		vector<long long>B(A.size()+1);
		B[A.size()]=1;
		X--;
		for(int i=A.size();i--;)
		{
			long long prv=B[i+1];
			if(A[i]<0)B[i]=prv;
			else
			{
				if(A[i]+1>X/prv)B[i]=X+1;
				else B[i]=prv*(A[i]+1);
			}
		}
		string ans="";
		for(int i=0;i<A.size();i++)
		{
			if(A[i]<0)ans+='a';
			else
			{
				long long nxt=B[i+1];
				while(X>=nxt)X-=nxt,ans+='b';
			}
		}
		cout<<ans<<"\n";
	}
}