#include<iostream>
#include<vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;string S;
		cin>>N>>S;
		vector<int>A[2];
		for(int i=0;i<N;i++)
		{
			if(S[2*i]!=S[2*i+1])
			{
				A[S[2*i]-'0'].push_back(2*i);
				A[S[2*i+1]-'0'].push_back(2*i+1);
			}
		}
		if(A[0].size()%2==1)
		{
			cout<<"-1\n";
			continue;
		}
		vector<int>B(A[0].size());
		for(int i=0;i<A[0].size();i++)B[i]=A[i%2][i];
		cout<<B.size();
		for(int i=0;i<B.size();i++)cout<<" "<<B[i]+1;
		cout<<"\n";
		string T=S;
		for(int i=0;i<B.size();i++)T[B[(i+1)%B.size()]]=S[B[i]];
		for(int i=0;i<N;i++)cout<<i*2+1<<(i+1==N?"\n":" ");
	}
}