#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N,W;
int A[100],B[100];
main()
{
	cin>>N>>W;
	vector<pair<int,int> >Ai(N);
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
		Ai[i]=make_pair(-A[i],i);
		B[i]=(A[i]+1)/2;
		W-=B[i];
	}
	sort(Ai.begin(),Ai.end());
	for(int i=0;i<N;i++)
	{
		int id=Ai[i].second;
		while(W>0&&B[id]<A[id])B[id]++,W--;
	}
	if(W==0)
	{
		for(int i=0;i<N;i++)cout<<B[i]<<(i+1==N?"\n":" ");
	}
	else cout<<-1<<endl;
}