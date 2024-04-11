#include <bits/stdc++.h>
using namespace std;
int n,m,h;
int oc[1000];
list<int> b;
list<int>::iterator it;
list<int>::iterator ite;
int c[200000];
int o[200000];
vector<int> a[200000];
int r[200000];
int ir[200000];
bool p[200000];
int ch[200000];
bool vis[200000];
pair<pair<int,int>,pair<int,int> > q[200000];
bool by_block(pair<pair<int,int>,pair<int,int> > x, pair<pair<int,int>,pair<int,int> > y)
{
	if(x.first.first/h==y.first.first/h) return x.first.second<y.first.second;
	else return x.first.first<y.first.first;
}
bool by_index(pair<pair<int,int>,pair<int,int> > x, pair<pair<int,int>,pair<int,int> > y)
{
	return x.second.first<y.second.first;
}
int l=0;
void dfs(int u)
{
	int v;
	r[l]=u;
	ir[u]=l;
	l++;
	p[u]=true;
	ch[u]=1;
	for(int i=0;i<a[u].size();i++)
	{
		v=a[u][i];
		if(!p[v])
		{
			dfs(v);
			ch[u]+=ch[v];
		}
	}
}
int main()
{
	int u,v,k;
	scanf("%d %d",&n,&m);
	h=sqrt(n);
	for(int i=0;i<n;i++) scanf("%d",&c[i+1]);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d",&u,&v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs(1);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&v,&k);
		q[i]=make_pair(make_pair(ir[v],ir[v]+ch[v]-1),make_pair(i,k));
	}
	int lb,rb;
	int cl=0;
	int cr=0;
	bool del;
	int sl;
	oc[1]=1;
	o[c[r[0]]]=1;
	sort(q,q+m,by_block);
	for(int i=0;i<m;i++)
	{
		lb=q[i].first.first;
		rb=q[i].first.second;
		k=q[i].second.second;
		//cout<<lb<<"   "<<rb<<" "<<k<<endl;
		while(cr<rb)
		{
			cr++;
			if(o[c[r[cr]]]<h) oc[o[c[r[cr]]]]--;
			o[c[r[cr]]]++;
			if(o[c[r[cr]]]<h) oc[o[c[r[cr]]]]++;
			if(o[c[r[cr]]]==h) b.push_back(c[r[cr]]);
		}
		while(cr>rb)
		{
			if(o[c[r[cr]]]<h) oc[o[c[r[cr]]]]--;
			o[c[r[cr]]]--;
			if(o[c[r[cr]]]<h) oc[o[c[r[cr]]]]++;
			cr--;
		}
		while(cl<lb)
		{
			if(o[c[r[cl]]]<h) oc[o[c[r[cl]]]]--;
			o[c[r[cl]]]--;
			if(o[c[r[cl]]]<h) oc[o[c[r[cl]]]]++;
			cl++;
		}
		while(cl>lb)
		{
			cl--;
			if(o[c[r[cl]]]<h) oc[o[c[r[cl]]]]--;
			o[c[r[cl]]]++;
			if(o[c[r[cl]]]<h) oc[o[c[r[cl]]]]++;
			if(o[c[r[cl]]]==h) b.push_back(c[r[cl]]);
		}
		it=b.begin();
		while(it!=b.end())
		{
			del=false;
			ite=it;
			if(vis[(*it)]) del=true;
			vis[(*it)]=true;
			it++;
			if(o[(*ite)]<h || del)
			{
				if(!del) vis[(*ite)]=false;
				b.erase(ite);
			}
		}
		it=b.begin();
		while(it!=b.end())
		{
			vis[(*it)]=false;
			it++;
		}
		sl=0;
		//cout<<o[1]<<" "<<o[2]<<" "<<o[3]<<endl;
		//cout<<oc[0]<<" "<<oc[1]<<" "<<oc[2]<<" "<<oc[3]<<" "<<oc[4]<<endl;
		for(int j=k;j<h;j++) sl+=oc[j];
		//cout<<sl<<endl;
		it=b.begin();
		while(it!=b.end())
		{
			if(o[(*it)]>=k) sl++;
			it++;
		}
		//cout<<sl<<endl;
		q[i]=make_pair(make_pair(lb,rb),make_pair(q[i].second.first,sl));
	}
	sort(q,q+m,by_index);
	for(int i=0;i<m;i++) printf("%d\n",q[i].second.second);
	return 0;
}