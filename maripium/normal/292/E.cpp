#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

pair<int,int> lazy[N<<2];
int a[N],b[N];
void dolazy(int i,int l,int r)
{
	if(lazy[i].first == 0) return;
	if(l == r)b[l] = a[l-lazy[i].second+lazy[i].first];
	else lazy[i<<1] = lazy[i<<1|1] = lazy[i];
	lazy[i]=make_pair(0,0);
}

void upd(int i,int l,int r,int x,int y,int len)
{
	dolazy(i,l,r);
	if(y > r || y+len <=l || l>r ) return;
	if(y <= l && y+len > r)
	{
		if(l == r) b[l] = a[l-y+x];
		else lazy[i<<1] = lazy[i<<1|1] = make_pair(x,y);
		return;
	}
	int mid= l+r >> 1;
	upd(i<<1,l,mid,x,y,len);
	upd(i<<1|1,mid+1,r,x,y,len);
}

int get(int i,int l,int r,int pos)
{
	dolazy(i,l,r);
	if(l > pos || r < pos) return 0;
	if(l == r) return b[l];
	int mid = l+r >> 1;
	return get(i<<1,l,mid,pos) + get(i<<1|1,mid+1,r,pos);
}

int main()
{
	int n,q;
	cin>>n>>q;
	for(int i = 1;i <= n; ++i)cin >> a[i];
	for(int i = 1;i <= n;++i)cin>>b[i];
	while(q--)
	{
		int type,x,y,len,pos;
		cin >> type;
		if(type == 1)
		{
		cin >> x >> y >> len;
		upd(1,1,n,x,y,len);
		}
		else {
			cin >> pos; cout << get(1,1,n,pos) << endl;
			}
	}
}