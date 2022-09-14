#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int f(int N){return N%4==0?N:N%4==1?1:N%4==2?N+1:0;}
int N,M;
const int LIM=50000,B=200;
int A[LIM];
int ans[5000];
vector<pair<pair<int,int>,int> >Qs[(LIM+B-1)/B];
int dat1[2<<20],dat2[2<<20],usd1[2<<20],usd2[2<<20];
int tm;
void add1(int X,int x)
{
	int p=0;
	for(int i=20;i--;)
	{
		int k=X>>i&1;
		p=p*2+k+1;
		if(usd1[p]!=tm||dat1[p]<x)
		{
			dat1[p]=x;
			usd1[p]=tm;
		}
	}
}
void add2(int X,int x)
{
	int p=0;
	for(int i=20;i--;)
	{
		int k=X>>i&1;
		p=p*2+k+1;
		if(usd2[p]!=tm||dat2[p]>x)
		{
			dat2[p]=x;
			usd2[p]=tm;
		}
	}
}
int get1(int X,int x)
{
	int p=0;
	int ret=0;
	for(int i=20;i--;)
	{
		int k=X>>i&1;
		p=p*2+2-k;
		ret<<=1;
		if(usd1[p]==tm&&dat1[p]>=x)ret|=1;
		else p+=-(2-k)+k+1;
	}
	return ret;
}
int get2(int X,int x)
{
	int p=0;
	int ret=0;
	for(int i=20;i--;)
	{
		int k=X>>i&1;
		p=p*2+2-k;
		ret<<=1;
		if(usd2[p]==tm&&dat2[p]<=x)ret|=1;
		else p+=-(2-k)+k+1;
	}
	return ret;
}
main()
{
	cin>>N>>M;
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=0;i<M;i++)
	{
		int l,r;cin>>l>>r;
		l--;
		Qs[l/B].push_back(make_pair(make_pair(r,l),i));
	}
	for(int i=0;i<(LIM+B-1)/B;i++)
	{
		int L=i*B,R=L+B;
		if(R>N)R=N;
		sort(Qs[i].begin(),Qs[i].end());
		int nr=R;
		int Rmax=0;
		tm++;
		for(int j=0;j<Qs[i].size();j++)
		{
			int r=Qs[i][j].first.first,l=Qs[i][j].first.second;
			int id=Qs[i][j].second;
			while(nr<r)
			{
				add1(f(A[nr]),A[nr]);
				add2(f(A[nr]-1),A[nr]);
				Rmax=max(Rmax,get1(f(A[nr]-1),A[nr]));
				Rmax=max(Rmax,get2(f(A[nr]),A[nr]));
				nr++;
			}
			ans[id]=max(ans[id],Rmax);
			if(R<r)
			{
				for(int li=l;li<R;li++)
				{
					ans[id]=max(ans[id],get1(f(A[li]-1),A[li]));
					ans[id]=max(ans[id],get2(f(A[li]),A[li]));
				}
			}
		}
		for(int j=0;j<Qs[i].size();j++)
		{
			int r=min(R,Qs[i][j].first.first),l=Qs[i][j].first.second;
			int id=Qs[i][j].second;
			tm++;
			for(int li=l;li<r;li++)
			{
				add1(f(A[li]),A[li]);
				add2(f(A[li]-1),A[li]);
				ans[id]=max(ans[id],get1(f(A[li]-1),A[li]));
				ans[id]=max(ans[id],get2(f(A[li]),A[li]));
			}
		}
	}
	for(int i=0;i<M;i++)cout<<ans[i]<<endl;
}