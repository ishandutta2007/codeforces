#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int n,nn;
pair<char,int> data[100005];
vector <int> idv;
map <int,int> vid;
bool debug;

struct form
{
	ll sum[5];
	int count;
}sgt[400005];

//void addbit(int x,int delta)
//{
//	{
//		adt=1;
//		return;
//	}
//	else if(x==0 && delta==-1)
//	{
//		adt=0;
//		return;
//	}
//	while(x<=nn)
//	{
//		bit[x]+=delta;
//		x+=x&-x;
//	}
//}

//int query(int x)
//{
//	int res=0;
//	while(x)
//	{
//		res+=bit[x];
//		x&=(x-1);
//	}
//	return res+adt;
//}

char getchr()
{
	char c=1;
	while(c!='a' && c!='d' && c!='s') c=getchar();
	return c;
}

int getnum()
{
	int res=0;
	char x=0;
	while(!isdigit(x))
	{
		x=getchar();
	}
	while(isdigit(x))
	{
		res=res*10+x-'0';
		x=getchar();
	}
	return res;
}

//void shift(int x)
//{
//	int temp=sum[x][4];
//	for(int i=4;i>=1;i--)
//	{
//		sum[x][i]=sum[x][i-1];
//	}
//	sum[x][0]=temp;
//}

//inline void push_down(int x,int l,int r)
//{
//	if(x>=nn) return;
//	tag[x]%=5;
//	for(int i=0;i<tag[x];i++)
//	{
//		shift(x*2);
//		shift(x*2+1);
//	}
//	tag[x*2]+=tag[x];
//	tag[x*2+1]+=tag[x];
//	tag[x]=0;
//}

//inline void push_up(int x,int l,int r)
//{
//	debug&=(x==2);
//	if(debug)
//	{
//		for(int i=1;i<nn*2;i++)
//		{
//			for(int k=0;k<5;k++)
//			{
//				cout<<sum[i][k]<<' ';
//			}
//			cout<<endl;
//		}
//	}
//	push_down(x,l,r);
//	for(int i=0;i<5;i++)
//	{
//		sum[x][i]=sum[x*2][i]+sum[x*2+1][(i+(query(r)-query((l+r>>1)-1)))%5];
//	}
//}

//void add(int x,int l,int r,int qx)
//{
////	if(debug) cout<<x<<' '<<l<<' '<<r<<' '<<qx<<endl;
//	if(r<=qx) return;
//	push_down(x,l,r);
//	if(l==qx && r-l==1)
//	{
////		if(debug) cout<<"FUCJ"<<' '<<x<<endl;
//		sum[x][0]+=idv[qx];
//		return;
//	}
//	if(l>qx)
//	{
//		tag[x]++;
//		shift(x);
//	}
//	else
//	{
//		add(x*2,l,l+r>>1,qx);
//		add(x*2+1,l+r>>1,r,qx);
//	}
//	push_up(x,l,r);
//}

//void del(int x,int l,int r,int qx)
//{
//	if(r<=qx) return;
//	push_down(x,l,r);
//	if(l==qx && r-l==1)
//	{
//		sum[x][0]-=idv[qx];
//		return;
//	}
//	if(l>=qx)
//	{
//		tag[x]++;
//		for(int i=0;i<4;i++)
//		{
//			shift(x);
//		}
//	}
//	else
//	{
//		add(x*2,l,l+r>>1,qx);
//		add(x*2+1,l+r>>1,r,qx);
//	}
//	push_up(x,l,r);
//}

inline void upd(int x)
{
	sgt[x].count=sgt[x*2].count+sgt[x*2+1].count;
	for(int i=0;i<5;i++)
	{
		sgt[x].sum[i]=sgt[x*2].sum[i]+sgt[x*2+1].sum[((5+i-sgt[x*2].count)%5+5)%5];
	}
}

void add(int x,int delta)
{
	sgt[x].count++;
	sgt[x].sum[0]=delta;
	x>>=1;
	while(x>=1)
	{
		upd(x);
		x>>=1;
	}
}

void del(int x,int delta)
{
	sgt[x].count--;
	sgt[x].sum[0]=0;
	x>>=1;
	while(x>=1)
	{
		upd(x);
		x>>=1;
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	nn=1;
	while(nn<=n)
	{
		nn<<=1;
	}
	for(int i=0;i<n;i++)
	{
		char c=getchr();
		if(c=='a')
		{
			data[i]={'a',getnum()};
			idv.push_back(data[i].second);
		}
		else if(c=='s')
		{
			data[i]={'s',0};
		}
		else
		{
			data[i]={'d',getnum()};
		}
	}
	sort(all(idv));
	idv.erase(unique(all(idv)),idv.end());
	for(int i=0;i<idv.size();i++)
	{
		vid[idv[i]]=i;
	}
//	for(int i=0;i<n;i++)
//	{
//		cout<<data[i].first<<' '<<data[i].second<<endl;
//	}
	for(int i=0;i<n;i++)
	{
		if(data[i].first=='a')
		{
			int pos=vid[data[i].second]+nn;
//			cout<<pos<<endl;
			add(pos,data[i].second);
		}
		else if(data[i].first=='s')
		{
//			push_down(1,0,nn);
			printf("%I64d\n",sgt[1].sum[2]);
		}
		else
		{
			int pos=vid[data[i].second]+nn;
			del(pos,data[i].second);
		}
	}
//	for(int i=1;i<nn*2;i++)
//	{
//		cout<<i<<'-'<<sgt[i].count<<':';
//		for(int k=0;k<5;k++)
//		{
//			cout<<sgt[i].sum[k]<<' ';
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	return 0;
}