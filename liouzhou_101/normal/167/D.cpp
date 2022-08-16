#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

const int MOD=1000000009;
const int MaxN=100010;

int n;
pair<int,int> p[MaxN];

struct node
{
	node *Lc,*Rc;
	int L,R,mid;
	pair<int,int> val;
}tree[MaxN],*root,*nil=&tree[0];

pair<int,int> calc(pair<int,int> L,pair<int,int> R)
{
	return make_pair(L.second+R.second,max(L.first+R.second,L.second+R.first)+1);
}

node *build(int L,int R)
{
	if (L>R) return nil;
	int x=max_element(p+L,p+R+1)-p;
	node *it=&tree[x];
	it->L=p[L].second;
	it->R=p[R].second;
	it->mid=p[x].second;
	it->Lc=build(L,x-1);
	it->Rc=build(x+1,R);
	it->val=calc(it->Lc->val,it->Rc->val);
	return it;
}

pair<int,int> solve(node *it,int L,int R)
{
	if (it==nil||it->R<L||it->L>R) return nil->val;
	if (L<=it->L&&it->R<=R) return it->val;
	if (R<it->mid) return solve(it->Lc,L,R);
	if (L>it->mid) return solve(it->Rc,L,R);
	return calc(solve(it->Lc,L,R),solve(it->Rc,L,R));
}

void init()
{
	int k;
	cin>>n>>k;
	for (int i=1;i<=k;++i)
		cin>>p[i].first>>p[i].second;
	long long a,b,c,d;
	cin>>a>>b>>c>>d;
	for (int i=k+1;i<=n;++i)
		p[i]=make_pair((p[i-1].first*a+b)%MOD,(p[i-1].second*c+d)%MOD);
	sort(p+1,p+n+1);
	for (int i=1;i<=n;++i)
		swap(p[i].first,p[i].second);
	nil->val=make_pair(-1,0);
	root=build(1,n);
}

void work()
{
	int T;
	cin>>T;
	while (T--)
	{
		int L,R;
		scanf("%d%d",&L,&R);
		printf("%d\n",solve(root,L,R).second);
	}
}

int main()
{
	init();
	work();
	return 0;
}