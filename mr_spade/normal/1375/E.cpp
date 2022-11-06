#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using std::swap;
using std::sort;
using std::vector;
const int N=1005;
int n;
int a[N],p[N];
int bk[N];
vector<int> V;
signed main()
{
	int x,y;
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]),p[i]=i;
	sort(p+1,p+n+1,[](int x,int y)->bool
	{
		if(a[x]!=a[y])
			return a[x]<a[y];
		return x<y;
	});
	for(i=1;i<=n;i++)
		a[p[i]]=i;
	end:;
	memset(bk+1,0,sizeof(int)*n);
	for(i=1;i<=n;i++)
	{
		if(bk[a[i]+1])
		{
			V.push_back(x=bk[a[i]+1]);V.push_back(y=i);swap(a[x],a[y]);
			goto end;
		}
		bk[a[i]]=i;
	}
	printf("%d\n",(int)V.size()/2);
	for(i=0;i<(int)V.size();i+=2)
		printf("%d %d\n",V[i],V[i+1]);
	return 0;
}