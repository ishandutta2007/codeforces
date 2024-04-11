#include<iostream>
#include<vector>
using namespace std;
int K;
main()
{
	cin>>K;
	vector<int>A;
	{
		string S;
		cin.ignore();
		getline(cin,S);
		for(int i=0;i<S.size();)
		{
			int j=i;
			while(j<S.size()&&S[j]!='-'&&S[j]!=' ')j++;
			if(j<S.size())j++;
			A.push_back(j-i);
			i=j;
		}
	}
	int L=0,R=2e6;
	while(R-L>1)
	{
		int mid=(L+R)/2;
		int now=0;
		for(int i=0;i<A.size();)
		{
			int j=i;
			int ret=mid;
			while(j<A.size()&&ret>=A[j])ret-=A[j++];
			i=j;
			now++;
			if(now>K)break;
		}
		if(now<=K)R=mid;
		else L=mid;
	}
	cout<<R<<endl;
}