#include <bits/stdc++.h>
#define pow lolol
// #pragma GCC optimize("O3")
using namespace std;
 
bool ch[200005][11];
int a[200005];
int po[20];
pair<int, int> it[800005][11];
 
int pow(int i, int j)
{
	return po[j];
}
 
pair<int, int> merge(pair<int, int> i, pair< int, int> j)
{
	if(i.second<j.first)
	{
		return i;
	}
	else if(j.second<i.first)
	{
		return j;
	}
	else return {min(i.first, j.first), max(i.first, j.first)};
}
 
void build_tree(int id, int l, int r)
{
	if(l==r)
	{
		for(int i=0; i<=9; i++)
		{
			if(ch[l][i])
			{
				it[id][i]={a[l], 1000000001};
			}
			else
			{
				it[id][i]={1000000001, 1000000001};
			}
		}
	}
	else
	{
		int mid=(l+r)/2;
		build_tree(id*2, l, mid);
		build_tree(id*2+1, mid+1, r);
		for(int i=0; i<=9; i++)
		{
			it[id][i]=merge(it[id*2][i], it[id*2+1][i]);
		}
	}
}
 
void update(int id, int l, int r, int pos)
{
//	cout<<id<<l<<" "<<r<<endl;
	if(l>pos||r<pos) return;
	if(l==pos&&r==pos)
	{
		for(int i=0; i<=9; i++)
		{
			if(ch[pos][i])
			{
				it[id][i]={a[pos], 1000000001};
			}
			else
			{
				it[id][i]={1000000001, 1000000001};
			}
		}
		return;
	}
	int mid=(l+r)/2;
	update(id*2, l, mid, pos);
	update(id*2+1, mid+1, r, pos);
	for(int i=0; i<=9; i++)
	{
		it[id][i]=merge(it[id*2][i], it[id*2+1][i]);
	}
}
 
pair<int, int> get(int type, int id, int l, int r, int u, int v)
{
	if(l>v||r<u) return {1000000001, 1000000001};
	if(l>=u&&r<=v)
	{
		return it[id][type];
	}
	int mid=(l+r)/2;
	return merge(get(type, id*2, l, mid, u, v), get(type, id*2+1, mid+1, r, u, v));
}
 
signed main()
{
    ios::sync_with_stdio(false);
	po[0]=1;
	for(int i=1; i<=12; i++)
	{
		po[i]=po[i-1]*10;
	}
	int n, q;
	cin>>n>>q;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		for(int j=0; j<=9; j++)
		{
			if((a[i]/po[j])%10!=0) ch[i][j]=true;
			else ch[i][j]=false;
		}
//		cout<<1;
	}
	build_tree(1, 1, n);
	for(int i=1; i<=q; i++)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			int pos, val;
			cin>>pos>>val;
			a[pos]=val;
			for(int j=0; j<=9; j++)
			{
				if((a[pos]/po[j])%10!=0) ch[pos][j]=true;
				else ch[pos][j]=false;
			}
			update(1, 1, n, pos);
		}
		else
		{
			int l, r;
			cin>>l>>r;
			int ans=2000000001;
			for(int j=0; j<=9; j++)
			{
				pair<int, int> lel=get(j, 1, 1, n, l, r);
				if(lel.second<=1000000000)
				ans=min(ans, {lel.first+lel.second});
			}
			if(ans>2000000000) cout<<-1;
			else cout<<ans;
			cout<<'\n';
		}
	}
}