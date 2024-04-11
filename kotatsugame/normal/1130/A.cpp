#include<iostream>
using namespace std;
int N;
main()
{
	cin>>N;
	int po=0,ne=0;
	for(int i=0;i<N;i++)
	{
		int a;cin>>a;
		po+=a>0;
		ne+=a<0;
	}
	cout<<(po*2>=N?1:ne*2>=N?-1:0)<<endl;
}