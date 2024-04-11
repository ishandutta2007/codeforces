#include<iostream>
using namespace std;
int L,N,A[1<<17];
int S[1<<17],F[1<<17];
int lp[1<<17],rp[1<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>L>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	int MN;
	{
		int l=1,r=L+1;
		while(r-l>1)
		{
			int mid=(l+r)/2;
			int pre=0;
			bool ok=true;
			for(int i=0;i<N;i++)
			{
				if(A[i]<pre)
				{
					ok=false;
					break;
				}
				pre=max(pre+mid,A[i]);
			}
			if(ok&&pre<=L)l=mid;
			else r=mid;
		}
		MN=l;
	}
	int MX;
	{
		int l=MN-1,r=L;
		while(r-l>1)
		{
			int mid=(l+r)/2;
			int pl=0,pr=0;
			bool ok=true;
			for(int i=0;i<N;i++)
			{
				if(pr>A[i])pr=A[i];
				if(pr<pl)
				{
					ok=false;
					break;
				}
				pl+=MN;
				pr+=mid;
				pl=max(pl,A[i]);
				if(pr<A[i])
				{
					ok=false;
					break;
				}
			}
			if(ok&&pl<=L&&L<=pr)r=mid;
			else l=mid;
		}
		MX=r;
	}
	{
		int pl=0,pr=0;
		for(int i=0;i<N;i++)
		{
			pl+=MN;
			pr+=MX;
			pl=max(pl,A[i]);
			if(i+1==N)lp[i]=rp[i]=L;
			else
			{
				if(pr>A[i+1])pr=A[i+1];
				lp[i]=pl;
				rp[i]=pr;
			}
		}
		int pos=L;
		for(int i=N-2;i>=0;i--)
		{
			int nxt=max(pos-MX,lp[i]);
			S[i+1]=nxt;
			F[i+1]=pos;
			pos=nxt;
		}
		S[0]=0;
		F[0]=pos;
		for(int i=0;i<N;i++)cout<<S[i]<<" "<<F[i]<<"\n";
	}
}