#include<iostream>
#include<algorithm>
using namespace std;
int N,W;
int A[100];
main()
{
	cin>>N>>W;
	for(int i=0;i<N;i++)cin>>A[i];
	sort(A,A+N);
	int cnt=0;
	while(W>0)W-=A[N-++cnt];
	cout<<cnt<<endl;
}