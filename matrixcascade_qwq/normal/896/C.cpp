
#include <bits/stdc++.h>
#define itt set<node>::iterator
#define pir pair<long long,long long>
#define int long long
#define mo 1000000007
using namespace std;

long long n,m,seed,vmax,op,x,y;

int a[1000001];

struct node{
	int l,r;
	mutable  int v;
	node (int ll,int rr=-1,int vv=0): l(ll),r(rr),v(vv){	}
	bool operator < (const node &u)const
	{
		return l<u.l;
	}
};
set<node>se;

int poww(int p,int q,int r)
{
	int res=1,ans=p%r;
    while(q)
	{
        if(q&1)
			res=res*ans%r;
        ans=ans*ans%r;
        q>>=1;
    }
    return res;
}


itt sp(int op)
{
	itt it=se.lower_bound(node(op));
	if(it!=se.end()&&it->l==op) return it;
	it--;
	int ll=it->l,rr=it->r,vv=it->v;
	se.erase(it);
	se.insert(node(ll,op-1,vv));
	return se.insert(node(op,rr,vv)).first;
}

int ans=0;
void ass(int ll,int rr,int vv)
{
	vector<itt>v;
	itt ir=sp(rr+1),il=sp(ll);
	while(il!=ir)se.erase(il++);
	se.insert(node(ll,rr,vv));
}

void add(int ll,int rr,int vv)
{
	itt itr=sp(rr+1),itl=sp(ll);
	for(;itl!=itr;++itl)
	{
		itl->v+=vv;
	}
}

int kth(int ll,int rr,int k)
{
	vector<pir>ve;
	itt itr=sp(rr+1),itl=sp(ll);
	for(;itl!=itr;++itl)
	{
		ve.push_back(pir(itl->v,itl->r-itl->l+1));
	}
	sort(ve.begin(),ve.end());
	for(vector<pir>::iterator it=ve.begin();it!=ve.end();++it)
	{
		k-=it->second;
		if(k<=0) return it->first;
	}
	return 0;
}

long long rnd()
{
    long long ret=seed;
    seed=(seed*7+13)%mo;
    return ret;
}

long long mcf(int l,int r,int x,int y){
	itt itr=sp(r+1),itl=sp(l);
	long long res=0;
	for(;itl!=itr;++itl)
	{
		res=(res+(itl->r-itl->l+1)*poww(itl->v,x,y)%y)%y;
	}
	return res;
}

signed main() {
	//freopen("zzb3.in","r",stdin);
	//freopen("123.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&seed,&vmax);
	for(int i=1;i<=n;++i)
	{
		a[i]=rnd()%vmax+1;
		se.insert(node(i,i,a[i]));
	}
	for(int i=1;i<=m;++i)
	{
		long long op=(rnd()%4)+1,l=(rnd()%n)+1,r=(rnd()%n)+1;
		if(l>r) swap(l,r);
		if(op==3)
        	x=(rnd()%(r-l+1))+1;
    	else
        	x=(rnd()%vmax)+1;
    	if(op==4)
        	y=(rnd()%vmax)+1;

		if(op==1)
		{
			add(l,r,x);
		}
		if(op==2)
		{
			ass(l,r,x);
		}
		if(op==3)
		{
			printf("%lld\n",kth(l,r,x));
		}
		if(op==4)
		{
			printf("%lld\n",mcf(l,r,x,y));
		}
	}
	return 0;
}