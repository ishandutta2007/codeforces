#include<iostream>
#include<vector>
using namespace std;
int N,K;
int A[100];
main()
{
	cin>>N>>K;
	for(int i=0;i<K;i++)cin>>A[i];
	int r=0;
	vector<int>a(N);
	for(int i=0;i<N;i++)a[i]=i+1;
	for(int i=0;i<K;i++)
	{
		r=(r+A[i])%a.size();
		cout<<a[r]<<(i+1==K?"\n":" ");
		a.erase(a.begin()+r);
		r%=a.size();
	}
}