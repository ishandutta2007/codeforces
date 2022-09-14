#line 1 "a.cpp"
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#line 2 "/home/kotatsugame/library/datastructure/UF.cpp"
struct UF{
	int n;
	vector<int>parent,rank;
	UF(int n_=0):n(n_),parent(n_),rank(n_,1)
	{
		for(int i=0;i<n_;i++)parent[i]=i;
	}
	int find(int a){return parent[a]!=a?parent[a]=find(parent[a]):a;}
	bool same(int a,int b){return find(a)==find(b);}
	bool unite(int a,int b)
	{
		a=find(a),b=find(b);
		if(a==b)return false;
		if(rank[a]<rank[b])
		{
			parent[a]=b;
			rank[b]+=rank[a];
		}
		else
		{
			parent[b]=a;
			rank[a]+=rank[b];
		}
		return true;
	}
	int size(int a){return rank[find(a)];}
};
#line 6 "a.cpp"
int N,Q,s,D;
int A[2<<17];
int L[2<<17],R[2<<17],K[2<<17],id[2<<17];
int mid[2<<17];
pair<int,pair<int,int> >calc(int i,int j)
{
	int d=abs(A[i]-A[j]);
	int k=abs(d-D);
	return make_pair(k,make_pair(i,j));
}
main()
{
	scanf("%d%d%d%d",&N,&Q,&s,&D);
	s--;
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	vector<pair<int,pair<int,int> > >E;
	{
		int l=0,r=0;
		for(int i=0;i<N;i++)
		{
			int nxA=i+1<N?A[i+1]:1e9;
			while(l<N)
			{
				E.push_back(calc(i,l));
				if(abs(A[i]-D-A[l])>abs(nxA-D-A[l]))break;
				l++;
			}
			if(l)l--;
			while(r<N)
			{
				E.push_back(calc(i,r));
				if(abs(A[i]+D-A[r])>abs(nxA+D-A[r]))break;
				r++;
			}
			if(r)r--;
		}
		sort(E.begin(),E.end());
	}
	for(int i=0;i<Q;i++)
	{
		scanf("%d%d",&id[i],&K[i]);
		id[i]--;
		L[i]=-1,R[i]=K[i]+1;
	}
	for(int _=0;_<22;_++)
	{
		vector<pair<int,int> >qs(Q);
		for(int i=0;i<Q;i++)
		{
			mid[i]=(L[i]+R[i])/2;
			qs[i]=make_pair(mid[i],i);
		}
		sort(qs.begin(),qs.end());
		int ei=0;
		UF uf(N);
		for(pair<int,int>p:qs)
		{
			while(ei<E.size()&&E[ei].first<=p.first)
			{
				uf.unite(E[ei].second.first,E[ei].second.second);
				ei++;
			}
			int ni=p.second;
			if(uf.same(s,id[ni]))R[ni]=mid[ni];
			else L[ni]=mid[ni];
		}
	}
	for(int i=0;i<Q;i++)puts(R[i]>K[i]?"No":"Yes");
}