#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>
using std::swap;
using std::sort;
using std::pair;
using std::make_pair;
using std::vector;
const int N=505;
int n;
int size[N],p[N];
vector<int> V;
vector<pair<int,int> > e;
signed main()
{
	int x,k,l,r,mid;
	register int i,j;
	scanf("%d",&n);
	size[1]=n;
	for(i=2;i<=n;i++)
	{
		printf("%d\n%d\n%d\n",1,1,n-1);
		for(j=2;j<=n;j++)
			printf("%d ",j);
		putchar('\n');
		printf("%d\n",i);
		fflush(stdout);
		scanf("%d",&size[i]);
	}
	for(i=1;i<=n;i++)
		p[i]=i;
	sort(p+1,p+n+1,[&](int a,int b)->bool
	{
		return size[a]<size[b];
	});
	V.push_back(p[1]);
	for(i=2;i<=n;i++)
	{
		if(V.empty())
		{
			V.push_back(p[i]);
			continue;
		}
		printf("%d\n%d\n%d\n",1,1,(int)V.size());
		for(auto x:V)
			printf("%d ",x);
		putchar('\n');
		printf("%d\n",p[i]);
		fflush(stdout);
		scanf("%d",&k);
		while(k--)
		{
			l=0;r=(int)V.size()-1;
			while(l<r)
			{
				mid=(l+r)>>1;
				printf("%d\n%d\n%d\n",1,1,mid+1);
				for(j=0;j<=mid;j++)
					printf("%d ",V[j]);
				putchar('\n');
				printf("%d\n",p[i]);
				fflush(stdout);
				scanf("%d",&x);
				if(x>0)
					r=mid;
				else
					l=mid+1;
			}
			e.push_back(make_pair(p[i],V[l]));
			swap(V[l],V[(int)V.size()-1]);V.pop_back();
		}
		V.push_back(p[i]);
	}
	puts("ANSWER");
	for(auto p:e)
		printf("%d %d\n",p.first,p.second);
	return 0;
}