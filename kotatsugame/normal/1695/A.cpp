#include<iostream>
using namespace std;
int T,H,W;
int A[40][40];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>H>>W;
		int mi=0,mj=0;
		for(int i=0;i<H;i++)for(int j=0;j<W;j++)
		{
			cin>>A[i][j];
			if(A[mi][mj]<A[i][j])mi=i,mj=j;
		}
		cout<<max(mi+1,H-mi)*max(mj+1,W-mj)<<"\n";
	}
}