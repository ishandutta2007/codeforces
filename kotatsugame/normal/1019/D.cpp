#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N;
long long S;
main()
{
	scanf("%d%lld",&N,&S);
	vector<pair<long long,long long> >A(N);
	for(int i=0;i<N;i++)scanf("%lld%lld",&A[i].first,&A[i].second);
	vector<pair<pair<long long,long long>,pair<int,int> > >dir;
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)if(i!=j)
	{
		dir.push_back(make_pair(
			make_pair(-A[i].second+A[j].second,A[i].first-A[j].first),
			make_pair(i,j)
		));
	}
	sort(dir.begin(),dir.end(),
	[](pair<pair<long long,long long>,pair<int,int> >&lhs,
		pair<pair<long long,long long>,pair<int,int> >&rhs)
	{
		long long lx=lhs.first.first,ly=lhs.first.second;
		long long rx=rhs.first.first,ry=rhs.first.second;
		int lt=ly==0?lx>0:ly>0;
		int rt=ry==0?rx>0:ry>0;
		if(lt!=rt)return lt<rt;
		return lx*ry-ly*rx>0;
	});
	vector<int>id(N),inv(N);
	long long x=dir.back().first.first,y=dir.back().first.second;
	for(int j=0;j<N;j++)id[j]=j;
	sort(id.begin(),id.end(),
	[&x,&y,&A](int l,int r)
	{
		long long lv=x*A[l].first+y*A[l].second;
		long long rv=x*A[r].first+y*A[r].second;
		return lv<rv;
	});
	for(int j=0;j<N;j++)inv[id[j]]=j;
	for(int i=0;i<dir.size();i++)
	{
		int l=dir[i].second.first,r=dir[i].second.second;
		swap(id[inv[l]],id[inv[r]]);
		swap(inv[l],inv[r]);
		int nl=0,nr=N;
		while(nr-nl>1)
		{
			int mi=(nl+nr)/2;
			long long a=A[l].first-A[id[mi]].first,b=A[l].second-A[id[mi]].second;
			long long c=A[r].first-A[id[mi]].first,d=A[r].second-A[id[mi]].second;
			if(a*d-b*c<S*2)nr=mi;
			else nl=mi;
		}
		long long a=A[l].first-A[id[nl]].first,b=A[l].second-A[id[nl]].second;
		long long c=A[r].first-A[id[nl]].first,d=A[r].second-A[id[nl]].second;
		if(a*d-b*c==S*2)
		{
			puts("Yes");
			printf("%lld %lld\n",A[l].first,A[l].second);
			printf("%lld %lld\n",A[r].first,A[r].second);
			printf("%lld %lld\n",A[id[nl]].first,A[id[nl]].second);
			return 0;
		}
	}
	puts("No");
}