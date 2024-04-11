#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N,M,K,S;
int A[2<<17],B[2<<17];
int iA[2<<17],iB[2<<17];
long long sa[2<<17],sb[2<<17];
main()
{
	scanf("%d%d%d%d",&N,&M,&K,&S);
	A[0]=B[0]=S+1;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&iA[i+1]);
		A[i+1]=min(iA[i+1],A[i]);
	}
	for(int i=0;i<N;i++)
	{
		scanf("%d",&iB[i+1]);
		B[i+1]=min(iB[i+1],B[i]);
	}
	vector<pair<int,int> >a,b;
	for(int i=0;i<M;i++)
	{
		int t,c;scanf("%d%d",&t,&c);
		if(t==1)a.push_back(make_pair(c,i));
		else b.push_back(make_pair(c,i));
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	for(int i=0;i<a.size();i++)sa[i+1]=sa[i]+a[i].first;
	for(int i=0;i<b.size();i++)sb[i+1]=sb[i]+b[i].first;
	int md=N+1;
	int mi;
	for(int i=0;i<=K;i++)
	{
		int j=K-i;
		if(i>a.size()||j>b.size())continue;
		long long X=sa[i],Y=sb[j];
		int l=0,r=N+1;
		while(r-l>1)
		{
			int mid=(l+r)/2;
			if(X*A[mid]+Y*B[mid]<=S)r=mid;
			else l=mid;
		}
		if(md>r)
		{
			md=r;
			mi=i;
		}
	}
	if(md==N+1)puts("-1");
	else
	{
		printf("%d\n",md);
		int mai=1,mbi=1;
		for(int i=2;i<=md;i++)
		{
			if(iA[mai]>iA[i])mai=i;
			if(iB[mbi]>iB[i])mbi=i;
		}
		for(int i=0;i<mi;i++)
		{
			printf("%d %d\n",a[i].second+1,mai);
		}
		for(int i=0;i<K-mi;i++)
		{
			printf("%d %d\n",b[i].second+1,mbi);
		}
	}
}