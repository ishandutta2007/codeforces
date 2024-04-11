#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#include<algorithm>
#include<list>
#include<cstdio>
#include<stack>
#include<cstring>
#include <climits>
#include<cmath>
#include<string>
#include <functional>
#include<sstream>
#include<map>
#include<set>

#pragma comment(linker, "/STACK:100000000000000")

using namespace std;
#define     For(i,a,b)        for (int i=a; i<b; i++)
#define     Rep(i,a)          for (int i=0; i<a; i++)
#define     ALL(v)            (v).begin(),(v).end()
#define     Set(a,x)          memset((a),(x),sizeof(a))
#define     EXIST(a,b)        find(ALL(a),(b))!=(a).end()
#define     Sort(x)           sort(ALL(x))
#define     UNIQUE(v)         Sort(v); (v).resize(unique(ALL(v)) - (v).begin())
#define     MP                make_pair
#define     SF                scanf
#define     PF                printf
#define     MAXN              501001
#define     MAXM              1001
#define     MOD               1000000007
#define     Dbug              cout<<"";
#define     EPS               1e-15
typedef long long ll;
typedef pair<int,int> pii;
struct node
{
	int l, r, ind, m;
	ll s;
	int lm;
}nd[MAXN];
int n, arr[MAXN];
void init(int l, int r, int i)
{
	if(l==r)
	{
		nd[i].l=nd[i].r=l, nd[i].ind=i;
		nd[i].s=arr[l];
		nd[i].m=arr[l]+1;
		return ;
	}
	nd[i].l=l, nd[i].r=r, nd[i].ind=i;
	init(l, (r+l)/2, i*2);
	init((r+l)/2+1, r, i*2+1);
	nd[i].s=nd[i*2].s+nd[i*2+1].s;
	nd[i].m=max(nd[i*2].m, nd[i*2+1].m);
}
ll sum(int l, int r, int i)
{
	if(l>nd[i].r || r<nd[i].l) return 0;
	if(l<=nd[i].l && r>=nd[i].r) return nd[i].s;
	ll p1=sum(l, r, i*2), p2=sum(l, r, i*2+1);
	return p1+p2;
}
void upd(int p, int x, int i)
{
	if(p>nd[i].r || p<nd[i].l) return ;
	if(nd[i].r==nd[i].l)
	{
		nd[i].m=x+1;
		nd[i].s=x;
		return ;
	}
	upd(p, x, i*2);
	upd(p, x, i*2+1);
	nd[i].s=nd[i*2].s+nd[i*2+1].s;
	nd[i].m=max(nd[i*2].m, nd[i*2+1].m);
}
void updmod(int l, int r, int x, int i)
{
	if(l>nd[i].r || r<nd[i].l) return ;
	if(nd[i].m<x) return;
	if(nd[i].r==nd[i].l)
	{
		nd[i].s%=x;
		nd[i].m=nd[i].s;
		return ;
	}
	updmod(l, r, x, i*2);
	updmod(l, r, x, i*2+1);
	nd[i].s=nd[i*2].s+nd[i*2+1].s;
	nd[i].m=max(nd[i*2].m, nd[i*2+1].m);
}
vector<pair<int, pair<int, pii> > > ord;
int main(){
	//ios_base::sync_with_stdio(false);
	//freopen("a.in","r",stdin);
	int q, a=0, b=0, c=0, d=0;
	SF("%d %d", &n, &q);
	Rep(i, n) SF("%d", &arr[i]);
	Rep(i, q)
	{
		SF("%d", &a);
		if(a==1)
		{
			SF("%d %d", &b, &c);
			ord.push_back(MP(a, MP(b, MP(c, d))));
		}
		else if(a==2)
		{
			SF("%d %d %d", &b, &c, &d);
			ord.push_back(MP(a, MP(b, MP(c, d))));
		}
		else 
		{
			SF("%d %d", &b, &c);
			ord.push_back(MP(a, MP(b, MP(c, d))));
		}
	}
	init(0, n-1, 1);
	int j=0, ind=-1;
	bool p=0;
	Rep(i, q)
	{
		if(ind==-1)
		{
			while(j<q)
			{
				if(ord[j].first==1) 
				{
					p=1;
					ind=j;
					j++;
					break;
				}
				j++;
			}
			if(p==0) break;
		}
		if(ord[i].first==1)
		{
			PF("%I64d\n", sum(ord[i].second.first-1, ord[i].second.second.first-1, 1));
		}
		else if(ord[i].first==3)
		{
			upd(ord[i].second.first-1, ord[i].second.second.first, 1);
		}
		//else if(i<ind) continue;
		else updmod(ord[i].second.first-1, ord[i].second.second.first-1, ord[i].second.second.second, 1);
		if(i==ind)
		{
			p=0;
			ind=-1;
		}
	}
	return 0;
}