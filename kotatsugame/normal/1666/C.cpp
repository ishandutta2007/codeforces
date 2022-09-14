#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int A[3],B[3];
main()
{
	for(int i=0;i<3;i++)cin>>A[i]>>B[i];
	vector<int>a(A,A+3),b(B,B+3);
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int pA=a[1],pB=b[1];
	int cnt=0;
	for(int i=0;i<3;i++)
	{
		if(pA!=A[i])cnt++;
		if(pB!=B[i])cnt++;
	}
	cout<<cnt<<endl;
	for(int i=0;i<3;i++)
	{
		if(pA!=A[i])cout<<pA<<" "<<pB<<" "<<A[i]<<" "<<pB<<endl;
		if(pB!=B[i])cout<<A[i]<<" "<<pB<<" "<<A[i]<<" "<<B[i]<<endl;
	}
}