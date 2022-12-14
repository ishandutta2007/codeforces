#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
using namespace std;
const long long mod=998244353;
long long n,q,tp,l,r,x,tree[888888],lazya[888888],lazym[888888],pre,sz,er;
set<pair<long long,long long> > s[222222];
set<pair<long long,long long> >::iterator it;
vector<set<pair<long long,long long> >::iterator> v;
void pushdown(long long node,long long s)
{
	tree[node*2]=(tree[node*2]*lazym[node]+lazya[node]*s)%mod;
	tree[node*2+1]=(tree[node*2+1]*lazym[node]+lazya[node]*s)%mod;
	lazym[node*2]=lazym[node*2]*lazym[node]%mod;
	lazya[node*2]=(lazya[node*2]*lazym[node]+lazya[node])%mod;
	lazym[node*2+1]=lazym[node*2+1]*lazym[node]%mod;
	lazya[node*2+1]=(lazya[node*2+1]*lazym[node]+lazya[node])%mod;
	lazya[node]=0;lazym[node]=1;
}
void add(long long beg,long long en,long long l,long long r,long long node)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en)
	{
		tree[node]=(tree[node]+r-l+1)%mod;
		lazya[node]=(lazya[node]+1)%mod;
		return;
	}
	pushdown(node,(r-l+1)/2);
	long long mid=(l+r)/2;
	add(beg,en,l,mid,node*2);
	add(beg,en,mid+1,r,node*2+1);
	tree[node]=(tree[node*2]+tree[node*2+1])%mod;
}
void mul(long long beg,long long en,long long l,long long r,long long node)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en)
	{
		tree[node]=tree[node]*2%mod;
		lazym[node]=lazym[node]*2%mod;
		lazya[node]=lazya[node]*2%mod;
		return;
	}
	pushdown(node,(r-l+1)/2);
	long long mid=(l+r)/2;
	mul(beg,en,l,mid,node*2);
	mul(beg,en,mid+1,r,node*2+1);
	tree[node]=(tree[node*2]+tree[node*2+1])%mod;
}
long long query(long long beg,long long en,long long l,long long r,long long node)
{
	if (l>en || r<beg) return 0;
	if (l>=beg && r<=en) return tree[node];
	long long mid=(l+r)/2;
	pushdown(node,(r-l+1)/2);
	return (query(beg,en,l,mid,node*2)+query(beg,en,mid+1,r,node*2+1))%mod;
}
int main()
{
	scanf("%I64d%I64d",&n,&q);
	sz=1;
	while(sz<n) sz*=2;
	while(q--)
	{
		scanf("%I64d",&tp);
		if (tp==1)
		{
			scanf("%I64d%I64d%I64d",&l,&r,&x);
			it=s[x].lower_bound(make_pair(l,0));
			v.clear();
			if (it!=s[x].begin())
			{
				it--;	
				mul(l,min(r,it->second),1,sz,1);
				pre=max(min(r,it->second)+1,l);
				if (it->second>r) er=it->second;
				else er=pre-1;
				if (it->second>=l)
				{
					l=it->first;
					v.push_back(it);
				}
				it++;
			}
			else 
			{
				pre=l;er=l-1;
			}
			for (;it!=s[x].end() && it->first<=r;it++)
			{
				add(pre,(it->first)-1,1,sz,1);
				mul(it->first,min(it->second,r),1,sz,1);
				pre=(it->second)+1;
				v.push_back(it);
				er=it->second;
			}
			add(er+1,r,1,sz,1);
			er=max(er,r);
			for (long long i=0;i<v.size();i++) s[x].erase(v[i]);
			s[x].insert(make_pair(l,er));  
		}
		else
		{
			scanf("%I64d%I64d",&l,&r);
			//for (int i=1;i<=n;i++) cout<<query(i,i,1,sz,1)<<" ";
			//cout<<endl;
			printf("%I64d\n",query(l,r,1,sz,1));
		}
	}
	return 0;
}