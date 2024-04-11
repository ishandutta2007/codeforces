#include<iostream>
using namespace std;
int N;
int A[1<<17];
int idx[1<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
		}
		for(int i=N;i--;)idx[A[i]]=i;
		int minr=N;
		int minl=N;
		for(int r=N-1;r>=0;r--)
		{
			if(r+1<N&&A[r]>A[r+1])break;
			minl=min(minl,idx[A[r]]);
			if(r==minl)minr=r;
		}
		int cnt=0;
		for(int i=0;i<minr;i++)if(idx[A[i]]==i)cnt++;
		cout<<cnt<<"\n";
	}
}