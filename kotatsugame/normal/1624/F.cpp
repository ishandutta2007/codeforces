#include<iostream>
using namespace std;
int N;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	int l=1,r=N;
	int sC=0;
	int q=0;
	while(r-l>1)
	{
		//N | sC+l or N | sC+r
		int mid=(l+r)/2;
		//N | sC+mid+nowC
		int nowC=(N-(sC+mid)%N)%N;
		cout<<"+ "<<nowC<<endl;
		int nq;cin>>nq;
		if(q<nq)l=mid;
		else r=mid;
		sC+=nowC;
		q=nq;
	}
	cout<<"! "<<l+sC<<endl;
}