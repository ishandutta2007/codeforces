#include<iostream>
#include<algorithm>
using namespace std;
int N;
string A[50505];
main()
{
	cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	sort(A,A+N,[](const string&a,const string&b){return a+b<b+a;});
	for(int i=0;i<N;i++)cout<<A[i];
	cout<<endl;
}