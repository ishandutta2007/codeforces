#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
main()
{
	cin>>N;
	vector<int>A(N);
	for(int i=0;i<N;i++)cin>>A[i];
	sort(A.begin(),A.end());
	A.erase(unique(A.begin(),A.end()),A.end());
	if(A.size()==1)cout<<0<<endl;
	else if(A.size()==2)
	{
		if(A[1]-A[0]&1)cout<<A[1]-A[0]<<endl;
		else cout<<(A[1]-A[0])/2<<endl;
	}
	else if(A.size()==3)
	{
		int u=A[0],v=A[1],w=A[2];
		if(w-v==v-u)cout<<w-v<<endl;
		else cout<<-1<<endl;
	}
	else cout<<-1<<endl;
}