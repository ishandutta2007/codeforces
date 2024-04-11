#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a[350000];
int c[350000];
int cyc[350000];
int d[350000];
int inv[350000];
vector<int> b[350000];
int k[350000];
int s=1;
void color(int u,int p)
{
	int v;
	int r;
	for(int i=0;i<a[u].size();i++)
	{
		v=a[u][i];
		if(p!=v)
		{
			if(c[v]==c[u])
			{
				if(d[v]<d[u]) cyc[u]=cyc[v];
			}
			else
			{
				d[v]=d[u]+1;
				c[v]=1-c[u];
				color(v,u);
				if(cyc[v]!=v) cyc[u]=cyc[v];
			}
		}
	}
}
pair<pair<int,int>,int > q[350000];
pair<int,long long int> ans[350000];
priority_queue<int> p[2];
bool inc[350000];
int h;
bool by_block(pair<pair<int,int>,int > x, pair<pair<int,int>,int > y)
{
	if(x.first.first/h==y.first.first/h) return x.first.second<y.first.second;
	else return x.first.first<y.first.first;
}
int main()
{
	int u,v;
	scanf("%d %d",&n,&m);
	h=sqrt(n);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v);
		u--;
		v--;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(int i=0;i<n;i++)
	{
		c[i]=-1;
		cyc[i]=i;
	}
	for(int i=0;i<n;i++)
	{
		if(c[i]==-1)
		{
			c[i]=0;
			color(i,-1);
		}
	}
	for(int i=0;i<n;i++) b[cyc[i]].push_back(i);
	int l,r;
	for(int i=0;i<n;i++)
	{
		if(b[i].size()>1)
		{
			l=b[i][0];
			r=b[i][0];
			for(int j=1;j<b[i].size();j++)
			{
				if(b[i][j]<l) l=b[i][j];
				if(b[i][j]>r) r=b[i][j]; 
			}
			k[l]=r+1;
			k[r]=l+1;
		}
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&l,&r);
		l--;
		r--;
		q[i]=make_pair(make_pair(l,r),i);
	}
	sort(q,q+m,by_block);
	int cl=0,cr=-1;
	int gl=-1,gr=-1;
	long long int sol=0;
	for(int i=0;i<m;i++)
	{
		l=q[i].first.first;
		r=q[i].first.second;
		while(cr<r)
		{
			cr++;
			if(k[cr]==0)
			{
				if(gl==-1) sol+=(cr-cl+1);
				else sol+=(cr-gl);
			}
			else
			{
				if(k[cr]-1<cr && k[cr]-1>=cl)
				{
					p[0].push(k[cr]-1);
					inc[k[cr]-1]=true;
					p[1].push(-cr);
					inc[cr]=true;
					gl=p[0].top();
					gr=-p[1].top();
				}
				if(gl==-1) sol+=(cr-cl+1);
				else sol+=(cr-gl);
			}
			//cout<<cl<<" "<<cr<<" "<<l<<" "<<r<<" "<<sol<<endl;
		}
		while(cl>l)
		{
			cl--;
			if(k[cl]==0)
			{
				if(gl==-1) sol+=(cr-cl+1);
				else sol+=(gr-cl);
			}
			else
			{
				if(k[cl]-1>cl && k[cl]-1<=cr)
				{
					p[0].push(cl);
					inc[cl]=true;
					p[1].push(-k[cl]+1);
					inc[k[cl]-1]=true;
					gl=p[0].top();
					gr=-p[1].top();
				}
				if(gl==-1) sol+=(cr-cl+1);
				else sol+=(gr-cl);
			}
			//cout<<cl<<" "<<cr<<" "<<l<<" "<<r<<" "<<sol<<endl;
		}
		while(cr>r)
		{
			if(k[cr]==0)
			{
				if(gl==-1) sol-=(cr-cl+1);
				else sol-=(cr-gl);
			}
			else
			{
				if(gl==-1) sol-=(cr-cl+1);
				else sol-=(cr-gl);
				if(k[cr]-1<cr && k[cr]-1>=cl)
				{
					inc[cr]=false;
					inc[k[cr]-1]=false;
					while(p[0].size()>0 && inc[p[0].top()]==false) p[0].pop();
					while(p[1].size()>0 && inc[-p[1].top()]==false) p[1].pop();
					if(p[0].size()==0)
					{
						gl=-1;
						gr=-1;
					}
					else
					{
						gl=p[0].top();
						gr=-p[1].top();
					}
				}
			}
			cr--;
			//cout<<cl<<" "<<cr<<" "<<l<<" "<<r<<" "<<sol<<endl;
		}
		while(cl<l)
		{
			if(k[cl]==0)
			{
				if(gl==-1) sol-=(cr-cl+1);
				else sol-=(gr-cl);
			}
			else
			{
				if(gl==-1) sol-=(cr-cl+1);
				else sol-=(gr-cl);
				if(k[cl]-1>cl && k[cl]-1<=cr)
				{
					inc[cl]=false;
					inc[k[cl]-1]=false;
					while(p[0].size()>0 && inc[p[0].top()]==false) p[0].pop();
					while(p[1].size()>0 && inc[-p[1].top()]==false) p[1].pop();
					if(p[0].size()==0)
					{
						gl=-1;
						gr=-1;
					}
					else
					{
						gl=p[0].top();
						gr=-p[1].top();
					}
				}
			}
			cl++;
		}
		ans[i]=make_pair(q[i].second,sol);
	}
	sort(ans,ans+m);
	for(int i=0;i<m;i++) printf("%lld\n",ans[i].second);
	return 0;
}