#include<iostream>
using namespace std;
struct dat{
	long long L,R,M,S;
};
dat op(const dat&l,const dat&r)
{
	dat ret;
	ret.L=max(l.L,l.S+r.L);
	ret.R=max(r.R,r.S+l.R);
	ret.M=max(max(l.M,r.M),l.R+r.L);
	ret.S=l.S+r.S;
	return ret;
}
dat A[19][1<<18];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin>>N;
	for(int i=0;i<1<<N;i++)
	{
		int a;cin>>a;
		A[0][i].L=max(a,0);
		A[0][i].R=max(a,0);
		A[0][i].M=max(a,0);
		A[0][i].S=a;
	}
	for(int k=1;k<=N;k++)
	{
		for(int i=0;i<1<<N;i++)
		{
			//int op=i>>k-1&1;
			//if(op==0)
			if(true)
			{
				A[k][i]=op(A[k-1][i],A[k-1][i^1<<k-1]);
			}
			else
			{
				A[k][i]=op(A[k-1][i],A[k-1][i^1<<k-1]);
			}
		}
	}
	int now=0;
	int Q;cin>>Q;
	for(;Q--;)
	{
		int k;cin>>k;
		now^=1<<k;
		cout<<A[N][now].M<<"\n";
	}
}