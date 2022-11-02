# include <iostream>
# include <cstdio>
# include <vector>
# include <algorithm>
using namespace std;

const int inf=~0U>>1;
const int N=100010;
#define M tree[u]
#define ML tree[u<<1]
#define MR tree[u<<1|1]

pair<int,int>p[N],q[N];
vector<int>C(9),e;

struct Seg{
	struct node{
		int l,r;
		vector<int>co;
	}tree[N<<2];
	void init(int u,int l,int r,int L,int R){
		M.l=l,M.r=r;
		int mid=(l+r)>>1,pp;
		for(int i=L;i<=R;i++){
			M.co.push_back(p[i].second);
			if(p[i].first<=e[mid])pp=i;
		}
		sort(M.co.begin(),M.co.end());
		if(l==r)return;
		init(u<<1,l,mid,L,pp);
		init(u<<1|1,mid+1,r,pp+1,R);
	}
	int query(int u,int x,int y){
		if(e[M.r]<=x)
			return upper_bound(M.co.begin(),M.co.end(),y)-M.co.begin();
		int ret=query(u<<1,x,y);
		if(e[MR.l]<=x) ret+=query(u<<1|1,x,y);
		return ret;
	}
}seg;

bool solve()
{
	static int x,xx,y,yy,a,b,c,d;
	a=C[0]+C[3]+C[6],b=a+C[1]+C[4]+C[7];
	x=p[a-1].first,xx=p[b-1].first;
	if(p[a].first==x||p[b].first==xx)return 0;
	c=C[0]+C[1]+C[2],d=c+C[3]+C[4]+C[5];
	y=q[c-1].first,yy=q[d-1].first;
	if(q[c].first==y||q[d].first==yy)return 0;
	if(seg.query(1,x,y)!=C[0])return 0;
	if(seg.query(1,xx,y)!=C[0]+C[1])return 0;
	if(seg.query(1,x,yy)!=C[0]+C[3])return 0;
	if(seg.query(1,xx,yy)!=C[0]+C[1]+C[3]+C[4])return 0;
	printf("%lf %lf\n%lf %lf\n",x+0.5,xx+0.5,y+0.5,yy+0.5);
	return true;
}

int main()
{
	int n,x,y; scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		p[i]=make_pair(x,y);
		q[i]=make_pair(y,x);
		e.push_back(x);
	}
	sort(e.begin(),e.end());
	e.erase(unique(e.begin(),e.end()),e.end());
	sort(p,p+n); sort(q,q+n);
	seg.init(1,0,e.size()-1,0,n-1);
	for(int i=0;i<9;i++)scanf("%d",&x),C[i]=x;
	sort(C.begin(),C.end());
	
	bool flag=false;
	do{
		flag=solve();
		if(flag)break;
	}while(next_permutation(C.begin(),C.end()));
	if(!flag)printf("-1\n");
	return 0;
}