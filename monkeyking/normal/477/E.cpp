//Original Code:
//#include <self/utility>
//#include <self/debug>
//#include <self/st-table>
//using namespace std;
//int n,q;
//int a[400005];
//int res[400005];
//pair<pii,pii> dat[400005];
//StTableFast <int> st; 
//
//
//struct MinyValue
//{
//	int minValue;
//	int minY;
//	MinyValue(int a,int b):minValue(a),minY(b){}
//	MinyValue(){}
//	inline bool operator < (const MinyValue &x)const&
//	{
//		if(minValue!=x.minValue) return minValue<x.minValue;
//		return minY<x.minY;
//	}
//};
//
//namespace Treap
//{
//	struct Node
//	{
//		int sz;
//		int rd;
//		int l;
//		int r;
//		MinyValue minValue;
//		MinyValue minData;
//		int key;
//		int i;
//		inline void pushup();
//	};
//	Node nodes[400005];
//	int rt;
//	int nodesCount;
//	inline void Node::pushup()
//	{
//		minValue=min(min(nodes[l].minValue,nodes[r].minValue),minData);
//		sz=nodes[l].sz+nodes[r].sz+1;
//	}
//	inline void init()
//	{
//		nodesCount=0;
//		Node &null=nodes[nodesCount++];
//		null.minValue=MinyValue(inf,inf);
//		rt=0;
//	}
//	int newNode(int i,int key)
//	{
//		Node &x=nodes[nodesCount];
//		x.minData=x.minValue=MinyValue(key-2*i,key);
//		x.rd=rand();
//		x.sz=1;
//		x.i=i;
//		x.key=key;
//		x.l=0;
//		x.r=0;
//		return nodesCount++;
//	}
//	inline int merge(int x,int y)
//	{
//		if(x==0) return y;
//		if(y==0) return x;
//		if(nodes[x].rd<nodes[y].rd)
//		{
//			nodes[y].l=merge(x,nodes[y].l);
//			nodes[y].pushup();
//			return y;
//		}
//		else
//		{
//			nodes[x].r=merge(nodes[x].r,y);
//			nodes[x].pushup();
//			return x;
//		}
//	}
//	inline pii splitByRow(int rt,int k) //?i<=row????
//	{
//		if(rt==0) return mp(0,0);
//		if(nodes[rt].i<=k)
//		{
//			pii r=splitByRow(nodes[rt].r,k);
//			nodes[rt].r=r.first;
//			nodes[rt].pushup();
//			return mp(rt,r.second);
//		}
//		else
//		{
//			pii l=splitByRow(nodes[rt].l,k);
//			nodes[rt].l=l.second;
//			nodes[rt].pushup();
//			return mp(l.first,rt);
//		}
//	}
//	inline pii splitByKey(int rt,int k) // ?key<=k????
//	{
//		if(rt==0) return mp(0,0);
//		if(nodes[rt].key<=k)
//		{
//			pii r=splitByKey(nodes[rt].r,k);
//			nodes[rt].r=r.first;
//			nodes[rt].pushup();
//			return mp(rt,r.second);
//		}
//		else
//		{
//			pii l=splitByKey(nodes[rt].l,k);
//			nodes[rt].l=l.second;
//			nodes[rt].pushup();
//			return mp(l.first,rt);
//		}
//	}
//	inline int rrrr(int rt)
//	{
//		int res=0;
//		while(rt!=0)
//		{
//			res=rt;
//			rt=nodes[rt].r;
//		}
//		return res;
//	}
//	inline int llll(int rt)
//	{
//		int res=0;
//		while(rt!=0)
//		{
//			res=rt;
//			rt=nodes[rt].l;
//		}
//		return res;
//	}
//	inline void pop_back(int &rt)
//	{
//		if(nodes[rt].r)
//		{
//			pop_back(nodes[rt].r);
//		}
//		else
//		{
//			rt=nodes[rt].l;
//		}
//		if(rt!=0) nodes[rt].pushup();
//	}
//	inline void print(int x=rt)
//	{
//		if(!x) return;
//		print(nodes[x].l);
//		cout<<mp(nodes[x].i,nodes[x].key)<<' ';
//		print(nodes[x].r);
//	}
//	inline void insert(int i,int key)
//	{
//		while(rt!=0 && nodes[rrrr(rt)].key>=key) pop_back(rt);
//		// print();
//		// cout<<mp(i,key)<<endl;
//		rt=merge(rt,newNode(i,key));
//	}
//}
//using Treap::insert;
//using Treap::splitByKey;
//using Treap::splitByRow;
//using Treap::merge;
//
//inline int calc(int sx,int sy,int ex,int ey)
//{
//	return abs(sx-ex)+abs(sy-ey);
//}
//
//namespace Solve1
//{
//	struct Query
//	{
//		int id;
//		int sx,sy,ex,ey;
//		Query(){}
//		Query(int e,int a,int b,int c,int d):id(e),sx(a),sy(b),ex(c),ey(d){}
//	};
//	vector<Query> queries[400005]; //????,??????,??????,???????
//	void solve()
//	{
//		for(int i=0;i<400005;i++)
//		{
//			queries[i].clear();
//		}
//		Treap::init();
//		for(int i=0;i<q;i++)
//		{
//			if(dat[i].first.first<dat[i].second.first)
//			{
//				queries[dat[i].second.first].push_back(Query(i,dat[i].first.first,dat[i].first.second,dat[i].second.first,dat[i].second.second));
//			}
//			else
//			{
//				queries[dat[i].second.first].push_back(Query(i,dat[i].first.first,dat[i].first.second,dat[i].second.first,dat[i].second.second));
//			}
//		}
//		for(int i=0;i<n;i++)
//		{
//			insert(i,a[i]);
//			// cout<<i<<' '<<"inserted"<<endl;
//			for(auto &Q:queries[i])
//			{
//				int ex,sx,ey,sy,qid;
//				qid=Q.id;
//				sx=Q.sx;
//				sy=Q.sy;
//				ex=Q.ex;
//				ey=Q.ey;
//				int &res=::res[qid];
//				if(ex>sx)
//				{
//					pii o=splitByRow(Treap::rt,sx-1); // can use o.second only
//					pii o2=splitByKey(o.second,ey);
//					if(o2.first)
//					{
//						Treap::Node &tmp=Treap::nodes[Treap::rrrr(o2.first)];
//						chmin(res,ex-sx+1+abs(tmp.key-ey));
//					}
//					if(o2.second)
//					{
//						Treap::Node &tmp=Treap::nodes[Treap::llll(o2.second)];
//						chmin(res,ex-sx+1+abs(tmp.key-ey));
//					}
//					Treap::rt=merge(o.first,merge(o2.first,o2.second));
//					
//					o2=splitByRow(Treap::rt,sx);
//					o=splitByKey(o2.first,ey);
//					if(o.first)
//					{
//						Treap::Node &tmp=Treap::nodes[Treap::rrrr(o.first)];
//						// cout<<tmp.key<<' '<<sy<<endl;
//						chmin(res,ex-tmp.i+(tmp.key<=sy?0:1)+sx-tmp.i+ey-tmp.key);
//						// cout<<"res="<<res<<endl;
//					}
//					if(o.second)
//					{
//						MinyValue minValue=Treap::nodes[o.second].minValue;
//						chmin(res,minValue.minValue+ex+sx+(minValue.minY<=sy?0:1)-ey);
//					}
//					Treap::rt=merge(merge(o.first,o.second),o2.second);
//				}
//				else
//				{
//					int b=sx-ex;
//					chmin(sy,st.query(ex,sx));
//					sx=ex;
//
//					pii o=splitByKey(Treap::rt,ey);
//					if(o.first)
//					{
//						Treap::Node &tmp=Treap::nodes[Treap::rrrr(o.first)];
//						chmin(res,b+2*(sx-tmp.i)+(tmp.key<=sy?0:1)+ey-tmp.key);
//					}
//					if(o.second)
//					{
//						MinyValue minValue=Treap::nodes[o.second].minValue;
//						chmin(res,minValue.minValue+b+(minValue.minY<=sy?0:1)+2*sx-ey);
//					}
//					Treap::rt=merge(o.first,o.second);
//				}
//			}
//		}
//	}
//}
//
//void solve()
//{
//	st.init(a,a+n);
//	for(int i=0;i<q;i++)
//	{
//		if(dat[i].first.first>dat[i].second.first) continue;
//		int colD=abs(dat[i].first.first-dat[i].second.first);
//		int ny=min(dat[i].first.second,st.query(dat[i].first.first,dat[i].second.first+1));
//		int ty=dat[i].second.second;
//		// cout<<res[0]<<endl;
//		// cout<<"colD="<<colD<<' '<<ny<<' '<<ty<<endl;
//		chmin(res[i],colD+abs(ny-ty));
//		// cout<<res[0]<<endl;
//		chmin(res[i],colD+1+ty);
//		// cout<<res[0]<<endl;
//	}
//	Solve1::solve();
//}
//
//int main()
//{
//	freopen("input.txt","r",stdin);
//	// freopen("1.out","w",stdout);
//	scanf("%d",&n);
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",a+i);
//	}
//	scanf("%d",&q);
//	for(int i=0;i<q;i++)
//	{
//		int a,b,c,d;
//		scanf("%d%d%d%d",&a,&b,&c,&d);
//		a--;
//		c--;
//		dat[i]=mp(mp(a,b),mp(c,d));
//	}
//	memset(res,0x3f,sizeof(res));
//	solve();
//	for(int i=0;i<q;i++)
//	{
//		dat[i].first.first=n-1-dat[i].first.first;
//		dat[i].second.first=n-1-dat[i].second.first;
//	}
//	for(int i=0;i<n/2;i++)
//	{
//		swap(a[i],a[n-1-i]);
//	}
//	// for(int i=0;i<n;i++)
//	// {
//	// 	cout<<a[i]<<' ';
//	// }
//	// cout<<endl;
//	// for(int i=0;i<q;i++)
//	// {
//	// 	cout<<dat[i]<<endl;
//	// }
//	solve();
//	for(int i=0;i<q;i++)
//	{
//		printf("%d\n",res[i]);
//	}
//	return 0;
//}

//substituted with C++ Inliner
#ifndef _SELF_UTILITY
#define _SELF_UTILITY 1
#include <numeric>
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
#include <assert.h>
#include <bitset>
#include <time.h>
#define Endl endl
#define mp make_pair
#define mt make_tuple
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define quickcin ios_base::sync_with_stdio(false);
#ifdef __TAKE_MOD
int mod;
#else
#ifdef __TAKE_CONST_MOD
const int mod=__TAKE_CONST_MOD;
#else
const int mod=1000000007;
#endif
#endif
const int gmod=5;
const int inf=1039074182;
const double eps=1e-9;
const ll llinf=2LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31 & mod);}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
template <typename T> inline T mabs(T x) {return (x<0?-x:x);}
#endif
using namespace std;
#ifndef _SELF_DEBUG
#define _SELF_DEBUG 1
#ifndef _SELF_OPERATOR
#define _SELF_OPERATOR 1
using namespace std;
template <typename T>
ostream &operator<<(ostream &cout, vector<T> vec)
{
	cout << "{";
	for (int i = 0; i < (int)vec.size(); i++)
	{
		cout << vec[i];
		if (i != (int)vec.size() - 1)
			cout << ',';
	}
	cout << "}";
	return cout;
}

template <typename T>
void operator*=(vector<T> &vec, int k)
{
	for (auto &x : vec)
		x *= k;
}

template <typename T>
void operator-=(vector<T> &a, const vector<T> &b)
{
	assert(a.size() == b.size());
	for (size_t it = 0; it < a.size(); it++)
	{
		a[it] -= b[it];
	}
}

template <typename T>
vector<T> operator*(const vector<T> &vec, int k)
{
	vector<T> res(vec);
	res *= k;
	return res;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &cout, pair<T1, T2> p)
{
	cout << "(" << p.first << ',' << p.second << ")";
	return cout;
}

template <typename T, typename T2>
ostream &operator<<(ostream &cout, set<T, T2> s)
{
	vector<T> t;
	for (auto x : s)
		t.push_back(x);
	cout << t;
	return cout;
}

template <typename T, typename T2>
ostream &operator<<(ostream &cout, multiset<T, T2> s)
{
	vector<T> t;
	for (auto x : s)
		t.push_back(x);
	cout << t;
	return cout;
}

template <typename T>
ostream &operator<<(ostream &cout, queue<T> q)
{
	vector<T> t;
	while (q.size())
	{
		t.push_back(q.front());
		q.pop();
	}
	cout << t;
	return cout;
}

template <typename T1, typename T2, typename T3>
ostream &operator<<(ostream &cout, map<T1, T2, T3> m)
{
	for (auto &x : m)
	{
		cout << "Key: " << x.first << ' ' << "Value: " << x.second << endl;
	}
	return cout;
}

template <typename T>
T operator*(vector<T> v1, vector<T> v2)
{
	assert(v1.size() == v2.size());
	int n = v1.size();
	T res = 0;
	for (int i = 0; i < n; i++)
	{
		res += v1[i] * v2[i];
	}
	return res;
}

template <typename T1, typename T2>
void operator+=(pair<T1, T2> &x,const pair<T1, T2> y)
{
	x.first += y.first;
	x.second += y.second;
}
template <typename T1,typename T2>
pair<T1,T2> operator + (const pair<T1,T2> &x,const pair<T1,T2> &y)
{
	return make_pair(x.first+y.first,x.second+y.second);
}

template <typename T1,typename T2>
pair<T1,T2> operator - (const pair<T1,T2> &x,const pair<T1,T2> &y)
{
	return mp(x.first-y.first,x.second-y.second);
}

template <typename T1, typename T2>
pair<T1, T2> operator-(pair<T1, T2> x)
{
	return make_pair(-x.first, -x.second);
}

template <typename T>
vector<vector<T>> operator~(vector<vector<T>> vec)
{
	vector<vector<T>> v;
	int n = vec.size(), m = vec[0].size();
	v.resize(m);
	for (int i = 0; i < m; i++)
	{
		v[i].resize(n);
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v[i][j] = vec[j][i];
		}
	}
	return v;
}
#endif
void print0x(int x)
{
	std::vector <int> vec;
	while(x)
	{
		vec.push_back(x&1);
		x>>=1;
	}
	std::reverse(vec.begin(),vec.end());
	for(int i=0;i<(int)vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}

template <typename T>
void print0x(T x,int len)
{
	std::vector <int> vec;
	while(x)
	{
		vec.push_back(x&1);
		x>>=1;
	}
	reverse(vec.begin(),vec.end());
	for(int i=(int)vec.size();i<len;i++)
	{
		putchar('0');
	}
	for(size_t i=0;i<vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}
#endif
#ifndef __SELF_ST_TABLE
#define __SELF_ST_TABLE 1

template <typename T,typename _Compare=std::less<T> >
struct StTableFast //
{
    std::vector <std::vector<T> > table;
    std::vector <int> logTable;
    _Compare comp;
    template <typename Iterator>
    void init(Iterator begin,Iterator end)
    {
        int n=end-begin;
        int lg=0;
        int nn=1;
        while(nn<=n)
        {
            nn<<=1;
            lg++;
        }
        lg--;
        table.resize(lg+1);
        for(int i=0;i<=lg;i++)
        {
            table[i].resize(n-(1<<i)+1);
        }
        logTable.resize(n+1);
        for(Iterator it=begin;it!=end;it++)
        {
            table[0][it-begin]=*it;
        }
        T ta,tb;
        for(int i=1;i<=lg;i++)
        {
            for(int j=0;j<n-(1<<i)+1;j++)
            {
                ta=table[i-1][j];
                tb=table[i-1][j+(1<<(i-1))];
                if(comp(ta,tb)) table[i][j]=ta;else table[i][j]=tb;
            }
        }
        logTable[1]=0;
        for(int i=2;i<=n;i++)
        {
            logTable[i]=logTable[i/2]+1;
        }
    }
    T query(int l,int r)
    {
        int n=r-l;
        int lg=logTable[n];
        T a=table[lg][l];
        T b=table[lg][r-(1<<lg)];
        if(comp(a,b)) return a;else return b;
    }
};

#endif
using namespace std;
int n,q;
int a[400005];
int res[400005];
pair<pii,pii> dat[400005];
StTableFast <int> st; 


struct MinyValue
{
	int minValue;
	int minY;
	MinyValue(int a,int b):minValue(a),minY(b){}
	MinyValue(){}
	inline bool operator < (const MinyValue &x)const&
	{
		if(minValue!=x.minValue) return minValue<x.minValue;
		return minY<x.minY;
	}
};

namespace Treap
{
	struct Node
	{
		int sz;
		int rd;
		int l;
		int r;
		MinyValue minValue;
		MinyValue minData;
		int key;
		int i;
		inline void pushup();
	};
	Node nodes[400005];
	int rt;
	int nodesCount;
	inline void Node::pushup()
	{
		minValue=min(min(nodes[l].minValue,nodes[r].minValue),minData);
		sz=nodes[l].sz+nodes[r].sz+1;
	}
	inline void init()
	{
		nodesCount=0;
		Node &null=nodes[nodesCount++];
		null.minValue=MinyValue(inf,inf);
		rt=0;
	}
	int newNode(int i,int key)
	{
		Node &x=nodes[nodesCount];
		x.minData=x.minValue=MinyValue(key-2*i,key);
		x.rd=rand();
		x.sz=1;
		x.i=i;
		x.key=key;
		x.l=0;
		x.r=0;
		return nodesCount++;
	}
	inline int merge(int x,int y)
	{
		if(x==0) return y;
		if(y==0) return x;
		if(nodes[x].rd<nodes[y].rd)
		{
			nodes[y].l=merge(x,nodes[y].l);
			nodes[y].pushup();
			return y;
		}
		else
		{
			nodes[x].r=merge(nodes[x].r,y);
			nodes[x].pushup();
			return x;
		}
	}
	inline pii splitByRow(int rt,int k) //?i<=row????
	{
		if(rt==0) return mp(0,0);
		if(nodes[rt].i<=k)
		{
			pii r=splitByRow(nodes[rt].r,k);
			nodes[rt].r=r.first;
			nodes[rt].pushup();
			return mp(rt,r.second);
		}
		else
		{
			pii l=splitByRow(nodes[rt].l,k);
			nodes[rt].l=l.second;
			nodes[rt].pushup();
			return mp(l.first,rt);
		}
	}
	inline pii splitByKey(int rt,int k) // ?key<=k????
	{
		if(rt==0) return mp(0,0);
		if(nodes[rt].key<=k)
		{
			pii r=splitByKey(nodes[rt].r,k);
			nodes[rt].r=r.first;
			nodes[rt].pushup();
			return mp(rt,r.second);
		}
		else
		{
			pii l=splitByKey(nodes[rt].l,k);
			nodes[rt].l=l.second;
			nodes[rt].pushup();
			return mp(l.first,rt);
		}
	}
	inline int rrrr(int rt)
	{
		int res=0;
		while(rt!=0)
		{
			res=rt;
			rt=nodes[rt].r;
		}
		return res;
	}
	inline int llll(int rt)
	{
		int res=0;
		while(rt!=0)
		{
			res=rt;
			rt=nodes[rt].l;
		}
		return res;
	}
	inline void pop_back(int &rt)
	{
		if(nodes[rt].r)
		{
			pop_back(nodes[rt].r);
		}
		else
		{
			rt=nodes[rt].l;
		}
		if(rt!=0) nodes[rt].pushup();
	}
	inline void print(int x=rt)
	{
		if(!x) return;
		print(nodes[x].l);
		cout<<mp(nodes[x].i,nodes[x].key)<<' ';
		print(nodes[x].r);
	}
	inline void insert(int i,int key)
	{
		while(rt!=0 && nodes[rrrr(rt)].key>=key) pop_back(rt);
		// print();
		// cout<<mp(i,key)<<endl;
		rt=merge(rt,newNode(i,key));
	}
}
using Treap::insert;
using Treap::splitByKey;
using Treap::splitByRow;
using Treap::merge;

inline int calc(int sx,int sy,int ex,int ey)
{
	return abs(sx-ex)+abs(sy-ey);
}

namespace Solve1
{
	struct Query
	{
		int id;
		int sx,sy,ex,ey;
		Query(){}
		Query(int e,int a,int b,int c,int d):id(e),sx(a),sy(b),ex(c),ey(d){}
	};
	vector<Query> queries[400005]; //????,??????,??????,???????
	void solve()
	{
		for(int i=0;i<400005;i++)
		{
			queries[i].clear();
		}
		Treap::init();
		for(int i=0;i<q;i++)
		{
			if(dat[i].first.first<dat[i].second.first)
			{
				queries[dat[i].second.first].push_back(Query(i,dat[i].first.first,dat[i].first.second,dat[i].second.first,dat[i].second.second));
			}
			else
			{
				queries[dat[i].second.first].push_back(Query(i,dat[i].first.first,dat[i].first.second,dat[i].second.first,dat[i].second.second));
			}
		}
		for(int i=0;i<n;i++)
		{
			insert(i,a[i]);
			// cout<<i<<' '<<"inserted"<<endl;
			for(auto &Q:queries[i])
			{
				int ex,sx,ey,sy,qid;
				qid=Q.id;
				sx=Q.sx;
				sy=Q.sy;
				ex=Q.ex;
				ey=Q.ey;
				int &res=::res[qid];
				if(ex>sx)
				{
					pii o=splitByRow(Treap::rt,sx-1); // can use o.second only
					pii o2=splitByKey(o.second,ey);
					if(o2.first)
					{
						Treap::Node &tmp=Treap::nodes[Treap::rrrr(o2.first)];
						chmin(res,ex-sx+1+abs(tmp.key-ey));
					}
					if(o2.second)
					{
						Treap::Node &tmp=Treap::nodes[Treap::llll(o2.second)];
						chmin(res,ex-sx+1+abs(tmp.key-ey));
					}
					Treap::rt=merge(o.first,merge(o2.first,o2.second));
					
					o2=splitByRow(Treap::rt,sx);
					o=splitByKey(o2.first,ey);
					if(o.first)
					{
						Treap::Node &tmp=Treap::nodes[Treap::rrrr(o.first)];
						// cout<<tmp.key<<' '<<sy<<endl;
						chmin(res,ex-tmp.i+(tmp.key<=sy?0:1)+sx-tmp.i+ey-tmp.key);
						// cout<<"res="<<res<<endl;
					}
					if(o.second)
					{
						MinyValue minValue=Treap::nodes[o.second].minValue;
						chmin(res,minValue.minValue+ex+sx+(minValue.minY<=sy?0:1)-ey);
					}
					Treap::rt=merge(merge(o.first,o.second),o2.second);
				}
				else
				{
					int b=sx-ex;
					chmin(sy,st.query(ex,sx));
					sx=ex;

					pii o=splitByKey(Treap::rt,ey);
					if(o.first)
					{
						Treap::Node &tmp=Treap::nodes[Treap::rrrr(o.first)];
						chmin(res,b+2*(sx-tmp.i)+(tmp.key<=sy?0:1)+ey-tmp.key);
					}
					if(o.second)
					{
						MinyValue minValue=Treap::nodes[o.second].minValue;
						chmin(res,minValue.minValue+b+(minValue.minY<=sy?0:1)+2*sx-ey);
					}
					Treap::rt=merge(o.first,o.second);
				}
			}
		}
	}
}

void solve()
{
	st.init(a,a+n);
	for(int i=0;i<q;i++)
	{
		if(dat[i].first.first>dat[i].second.first) continue;
		int colD=abs(dat[i].first.first-dat[i].second.first);
		int ny=min(dat[i].first.second,st.query(dat[i].first.first,dat[i].second.first+1));
		int ty=dat[i].second.second;
		// cout<<res[0]<<endl;
		// cout<<"colD="<<colD<<' '<<ny<<' '<<ty<<endl;
		chmin(res[i],colD+abs(ny-ty));
		// cout<<res[0]<<endl;
		chmin(res[i],colD+1+ty);
		// cout<<res[0]<<endl;
	}
	Solve1::solve();
}

int main()
{
//	freopen("input.txt","r",stdin);
	// freopen("1.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		a--;
		c--;
		dat[i]=mp(mp(a,b),mp(c,d));
	}
	memset(res,0x3f,sizeof(res));
	solve();
	for(int i=0;i<q;i++)
	{
		dat[i].first.first=n-1-dat[i].first.first;
		dat[i].second.first=n-1-dat[i].second.first;
	}
	for(int i=0;i<n/2;i++)
	{
		swap(a[i],a[n-1-i]);
	}
	// for(int i=0;i<n;i++)
	// {
	// 	cout<<a[i]<<' ';
	// }
	// cout<<endl;
	// for(int i=0;i<q;i++)
	// {
	// 	cout<<dat[i]<<endl;
	// }
	solve();
	for(int i=0;i<q;i++)
	{
		printf("%d\n",res[i]);
	}
	return 0;
}