#include<iostream>
using namespace std;
string A,B;
int L[1<<17],R[1<<17];
main()
{
	cin>>A>>B;
	L[0]=0;
	for(int i=0;i<B.size();i++)
	{
		L[i+1]=L[i];
		if(L[i+1]>A.size())L[i+1]=A.size();
		while(L[i+1]<A.size()&&A[L[i+1]]!=B[i])L[i+1]++;
		L[i+1]++;
	}
	R[B.size()]=A.size();
	for(int i=B.size();i--;)
	{
		R[i]=R[i+1]-1;
		if(R[i]<0)R[i]=-1;
		while(R[i]>=0&&A[R[i]]!=B[i])R[i]--;
	}
	int ans=B.size(),al=0,ar=B.size();
	int r=0;
	for(int l=0;l<=B.size();l++)
	{
		while(r<B.size()&&(l>r||L[l]>R[r]))r++;
		if(L[l]<=A.size()&&R[r]!=-1&&ans>r-l)
		{
			ans=r-l;
			al=l;
			ar=r;
		}
	}
	string ret=B.substr(0,al)+B.substr(ar);
	if(ret.empty())ret="-";
	cout<<ret<<endl;
}