#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N,M;
	cin>>N>>M;
	vector<pair<string,int> >A(N);
	for(int i=0;i<N;i++)
	{
		string S;cin>>S;
		for(int j=1;j<S.size();j+=2)S[j]='Z'-(S[j]-'A');
		A[i]=make_pair(S,i+1);
	}
	sort(A.begin(),A.end());
	for(int i=0;i<N;i++)cout<<A[i].second<<(i+1==N?"\n":" ");
}