#include<bits/stdc++.h>
using namespace std;
int n,m,sz,ct;
int tree[2][1111111];//0:x,1:y
int query(int beg,int en,int l,int r,int node,int id)
{
	if (l>en || r<beg) return 0;
	if (l>=beg && r<=en) return tree[id][node];
	int mid=(l+r)>>1;
	return max(query(beg,en,l,mid,node<<1,id),query(beg,en,mid+1,r,(node<<1)|1,id));
}
void upd(int id,int x,int y)
{
	int pos=sz-1+x;
	tree[id][pos]=y;pos>>=1;
	while(pos>=1)
	{
		tree[id][pos]=max(tree[id][pos<<1],tree[id][(pos<<1)|1]);
		pos>>=1;
	}
}
int x,y,tp,xtoy[555555],ytox[555555],cur;
set<int> px,py;
vector<pair<int,int> > v;
int main()
{
	scanf("%d%d",&n,&m);
	sz=1<<19;
	while(m--)
	{
		scanf("%d",&tp);
		if (tp==1)
		{
			scanf("%d%d",&x,&y);
			y+=m;
			px.insert(x);py.insert(y);
			xtoy[x]=y;ytox[y]=x;
			v.clear();
			for (set<int>::iterator it=py.begin();it!=py.end();it++)
			{
				v.push_back(make_pair(ytox[*it],*it));
				upd(0,ytox[*it],0);
				upd(1,*it,0); 
				if ((*it)==y) break;
			}  
			for (int i=(int)v.size()-1;i>=0;i--)
			{
				cur=query(v[i].first+1,sz,1,sz,1,0)+1;
				upd(0,v[i].first,cur);
				upd(1,v[i].second,cur);
			}
		}
		else
		{
			scanf("%d",&x);
			v.clear();
			int ct=1;
			for (set<int>::iterator it=px.begin();it!=px.end() && ct<=x;it++,ct++)
			{
				upd(0,*it,0);
				upd(1,xtoy[*it],0);
				if (ct==x)
				{
					int val=*it;
					py.erase(py.find(xtoy[val])); 
					px.erase(it);
					ytox[xtoy[val]]=0; 
					xtoy[val]=0;
					break;
				}
				else
				{
					v.push_back(make_pair(*it,xtoy[*it])); 
				}
			}
			for (int i=(int)v.size()-1;i>=0;i--)
			{
				cur=query(v[i].second+1,sz,1,sz,1,1)+1;
				upd(0,v[i].first,cur);
				upd(1,v[i].second,cur);
			}
		}
		printf("%d\n",query(1,sz,1,sz,1,0));
	}
	return 0;
}