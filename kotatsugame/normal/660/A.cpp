#include<iostream>
using namespace std;
int N;
int A[1000];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
main()
{
	cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	int cnt=0;
	for(int i=1;i<N;i++)cnt+=gcd(A[i-1],A[i])>1;
	cout<<cnt<<endl;
	cout<<A[0];
	for(int i=1;i<N;i++)
	{
		if(gcd(A[i-1],A[i])>1)cout<<" 1";
		cout<<" "<<A[i];
	}
	cout<<endl;
}