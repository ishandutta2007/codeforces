//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//
//int states;
//struct State
//{
//	int len;
//	int id;
//	int v=-1;
//	State *link[21];
//	State *go[27];
//	State(int _len){id=states++;len=_len;memset(go,0,sizeof(go));memset(link,0,sizeof(link));}
//};
//State *last,*root;
//vector<State*> vs;
//
//inline void extend(int w,int id)
//{
//	State *T=last;
//	State *Tx=new State(T->len+1);
//	vs.push_back(Tx);
//	Tx->v=id;
//	last=Tx;
//	while(T && T->go[w]==0)
//	{
//		T->go[w]=Tx;
//		T=T->link[0];
//	}
//	if(T==0)
//	{
//		Tx->link[0]=root;
//		return;
//	}
//	State *p=T->go[w];
//	if(p->len==T->len+1)
//	{
//		Tx->link[0]=p;
//	}
//	else
//	{
//		State *np=new State(T->len+1);
//		vs.push_back(np);
//		memcpy(np->go,p->go,sizeof(p->go));
//		np->link[0]=p->link[0];
//		p->link[0]=np;
//		Tx->link[0]=np;
//		while(T && T->go[w]==p)
//		{
//			T->go[w]=np;
//			T=T->link[0];
//		}
//	}
//}
//char buf[1550005];
//char c[1550005];
//int n;
//int k,m;
//State* ed[1550005];
//int l[1550005];
//int r[1550005];
//vector<int> vec[1550005];
//int visit[1550005];
//int a[1550005];
//
//void build(State *x)
//{
//	if(visit[x->id]) return;
//	visit[x->id]=true;
//	a[x->id]=x->v;
//	for(int i=0;i<27;i++)
//	{
//		if(x->go[i]) build(x->go[i]);
//	}
//	if(x!=root) vec[x->link[0]->id].push_back(x->id);
//}
//
//vector<int> va;
//void go(int x)
//{
//	static int dfn=0;
//	l[x]=dfn;
//	if(a[x]!=-1) dfn++,va.push_back(a[x]);
//	for(auto u:vec[x])
//	{
//		go(u);
//	}
//	r[x]=dfn;
//	// debug(x,l[x],r[x],a[x]);
//}
//
//struct Answer
//{
//	int cnt;
//	int id;
//	inline bool operator < (const Answer &oth)const
//	{
//		if(cnt!=oth.cnt) return cnt>oth.cnt;
//		return id<oth.id;
//	}
//};
//ostream & operator << (ostream &cout,const Answer &ans)
//{
//	cout<<mp(ans.cnt,ans.id);
//	return cout;
//}
//Answer worst={-1,inf};
//
//struct Node
//{
//	Answer ans;
//	Node *l=0,*r=0;
//	inline void pushup()
//	{
//		ans=min((l?l->ans:worst),(r?r->ans:worst));
//	}
//};
//
//struct SegmentTree
//{
//	Node *root=0;
//	SegmentTree(int reg) {}
//	inline void extend(Node *&x,int id,int l,int r)
//	{
//		if(r<=id || l>id) return;
//		if(x==0) x=new Node({worst});
//		if(r-l==1)
//		{
//			if(x->ans.cnt==-1) x->ans={0,id};
//			x->ans.cnt++;
//			// debug(x->ans);
//			return;
//		}
//		extend(x->l,id,l,(l+r)>>1);
//		extend(x->r,id,(l+r)>>1,r);
//		x->pushup();
//	}
//	inline Answer query(Node *x,int l,int r,int ql,int qr)
//	{
//		if(!x) return worst;
//		if(r<=ql || l>=qr) return worst;
//		if(l>=ql && r<=qr) return x->ans;
//		return min(query(x->l,l,(l+r)>>1,ql,qr),query(x->r,(l+r)>>1,r,ql,qr));
//	}
//	inline Answer query(int l,int r)
//	{
//		return query(root,0,m,l,r);
//	}
//	inline void extend(int id) {extend(root,id,0,m);}
//};
//
//inline Node* merge(Node *x,Node *y,int l,int r,bool debug=false)
//{
//	if(!x) return y;
//	if(!y) return x;
//	x->l=merge(x->l,y->l,l,(l+r)>>1,debug);
//	x->r=merge(x->r,y->r,(l+r)>>1,r,debug);
//	// if(r-l==1) debug(x->ans,y->ans);
//	if(r-l==1) x->ans.cnt+=y->ans.cnt;
//	else x->pushup();
//	delete y;
//	return x;
//}
//inline SegmentTree merge(SegmentTree a,SegmentTree b,bool debug=false)
//{
//	a.root=merge(a.root,b.root,0,m,debug);
//	return a;
//}
//vector<pair<int,pii> > queries[1550005];
//Answer res[1550005];
//
//SegmentTree dfs(int x)
//{
//	SegmentTree sgt(m);
//	for(auto u:vec[x])
//	{
//		// debug(x,u);
//		sgt=merge(sgt,dfs(u),x==1 && u==3);
//	}
//	for(auto &q:queries[x])
//	{
//		int id=q.first;
//		int l=q.second.first;
//		int r=q.second.second;
//		res[id]=sgt.query(l,r);
//		if(res[id].cnt==-1) res[id]=Answer({0,l});
//	}
//	if(a[x]!=-1) sgt.extend(a[x]);
//	return sgt;
//}
//
//int main()
//{
//	freopen("input.txt","r",stdin);
//	last=root=new State(0);
//	scanf("%s",c);
//	n=strlen(c);
//	for(int i=0;i<n;i++)
//	{
//		extend(c[i]-'a',-1);
//	}
//	scanf("%d",&k);
//	for(int i=0;i<k;i++)
//	{
//		extend('{'-'a',-1);
//		scanf("%s",buf);
//		int len=strlen(buf);
//		for(int j=0;j<len;j++)
//		{
//			extend(buf[j]-'a',i);
//		}
//	}
//	for(int i=0;i<n;i++)
//	{
//		ed[i]=(i?ed[i-1]:root)->go[c[i]-'a'];
//	}
//	for(int k=1;k<=20;k++)
//	{
//		for(auto &x:vs)
//		{
//			x->link[k]=(x->link[k-1]?x->link[k-1]->link[k-1]:0);
//		}
//	}
//	build(root);
//	go(0);
//	m=va.size();
//	int q;
//	scanf("%d",&q);
//	for(int i=0;i<q;i++)
//	{
//		int l,r,cl,cr;
//		scanf("%d%d%d%d",&l,&r,&cl,&cr);
//		l--;
//		cl--;
//		State *x=ed[cr-1];
//		for(int k=20;k>=0;k--)
//		{
//			if(x->link[k] && x->link[k]->len>=cr-cl) x=x->link[k];
//		}
//		queries[x->id].push_back(mp(i,mp(l,r)));
//	}
//	dfs(0);
//	for(int i=0;i<q;i++)
//	{
//		printf("%d %d\n",res[i].id+1,res[i].cnt);
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
const int gmod=3;
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
#include <sstream>
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
vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#endif
using namespace std;

int states;
struct State
{
	int len;
	int id;
	int v=-1;
	State *link[21];
	State *go[27];
	State(int _len){id=states++;len=_len;memset(go,0,sizeof(go));memset(link,0,sizeof(link));}
};
State *last,*root;
vector<State*> vs;

inline void extend(int w,int id)
{
	State *T=last;
	State *Tx=new State(T->len+1);
	vs.push_back(Tx);
	Tx->v=id;
	last=Tx;
	while(T && T->go[w]==0)
	{
		T->go[w]=Tx;
		T=T->link[0];
	}
	if(T==0)
	{
		Tx->link[0]=root;
		return;
	}
	State *p=T->go[w];
	if(p->len==T->len+1)
	{
		Tx->link[0]=p;
	}
	else
	{
		State *np=new State(T->len+1);
		vs.push_back(np);
		memcpy(np->go,p->go,sizeof(p->go));
		np->link[0]=p->link[0];
		p->link[0]=np;
		Tx->link[0]=np;
		while(T && T->go[w]==p)
		{
			T->go[w]=np;
			T=T->link[0];
		}
	}
}
char buf[1550005];
char c[1550005];
int n;
int k,m;
State* ed[1550005];
int l[1550005];
int r[1550005];
vector<int> vec[1550005];
int visit[1550005];
int a[1550005];

void build(State *x)
{
	if(visit[x->id]) return;
	visit[x->id]=true;
	a[x->id]=x->v;
	for(int i=0;i<27;i++)
	{
		if(x->go[i]) build(x->go[i]);
	}
	if(x!=root) vec[x->link[0]->id].push_back(x->id);
}

vector<int> va;
void go(int x)
{
	static int dfn=0;
	l[x]=dfn;
	if(a[x]!=-1) dfn++,va.push_back(a[x]);
	for(auto u:vec[x])
	{
		go(u);
	}
	r[x]=dfn;
	// debug(x,l[x],r[x],a[x]);
}

struct Answer
{
	int cnt;
	int id;
	inline bool operator < (const Answer &oth)const
	{
		if(cnt!=oth.cnt) return cnt>oth.cnt;
		return id<oth.id;
	}
};
ostream & operator << (ostream &cout,const Answer &ans)
{
	cout<<mp(ans.cnt,ans.id);
	return cout;
}
Answer worst={-1,inf};

struct Node
{
	Answer ans;
	Node *l=0,*r=0;
	inline void pushup()
	{
		ans=min((l?l->ans:worst),(r?r->ans:worst));
	}
};

struct SegmentTree
{
	Node *root=0;
	SegmentTree(int reg) {}
	inline void extend(Node *&x,int id,int l,int r)
	{
		if(r<=id || l>id) return;
		if(x==0) x=new Node({worst});
		if(r-l==1)
		{
			if(x->ans.cnt==-1) x->ans={0,id};
			x->ans.cnt++;
			// debug(x->ans);
			return;
		}
		extend(x->l,id,l,(l+r)>>1);
		extend(x->r,id,(l+r)>>1,r);
		x->pushup();
	}
	inline Answer query(Node *x,int l,int r,int ql,int qr)
	{
		if(!x) return worst;
		if(r<=ql || l>=qr) return worst;
		if(l>=ql && r<=qr) return x->ans;
		return min(query(x->l,l,(l+r)>>1,ql,qr),query(x->r,(l+r)>>1,r,ql,qr));
	}
	inline Answer query(int l,int r)
	{
		return query(root,0,m,l,r);
	}
	inline void extend(int id) {extend(root,id,0,m);}
};

inline Node* merge(Node *x,Node *y,int l,int r,bool debug=false)
{
	if(!x) return y;
	if(!y) return x;
	x->l=merge(x->l,y->l,l,(l+r)>>1,debug);
	x->r=merge(x->r,y->r,(l+r)>>1,r,debug);
	// if(r-l==1) debug(x->ans,y->ans);
	if(r-l==1) x->ans.cnt+=y->ans.cnt;
	else x->pushup();
	delete y;
	return x;
}
inline SegmentTree merge(SegmentTree a,SegmentTree b,bool debug=false)
{
	a.root=merge(a.root,b.root,0,m,debug);
	return a;
}
vector<pair<int,pii> > queries[1550005];
Answer res[1550005];

SegmentTree dfs(int x)
{
	SegmentTree sgt(m);
	for(auto u:vec[x])
	{
		// debug(x,u);
		sgt=merge(sgt,dfs(u),x==1 && u==3);
	}
	for(auto &q:queries[x])
	{
		int id=q.first;
		int l=q.second.first;
		int r=q.second.second;
		res[id]=sgt.query(l,r);
		if(res[id].cnt==-1) res[id]=Answer({0,l});
	}
	if(a[x]!=-1) sgt.extend(a[x]);
	return sgt;
}

int main()
{
//	freopen("input.txt","r",stdin);
	last=root=new State(0);
	scanf("%s",c);
	n=strlen(c);
	for(int i=0;i<n;i++)
	{
		extend(c[i]-'a',-1);
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		extend('{'-'a',-1);
		scanf("%s",buf);
		int len=strlen(buf);
		for(int j=0;j<len;j++)
		{
			extend(buf[j]-'a',i);
		}
	}
	for(int i=0;i<n;i++)
	{
		ed[i]=(i?ed[i-1]:root)->go[c[i]-'a'];
	}
	for(int k=1;k<=20;k++)
	{
		for(auto &x:vs)
		{
			x->link[k]=(x->link[k-1]?x->link[k-1]->link[k-1]:0);
		}
	}
	build(root);
	go(0);
	m=va.size();
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int l,r,cl,cr;
		scanf("%d%d%d%d",&l,&r,&cl,&cr);
		l--;
		cl--;
		State *x=ed[cr-1];
		for(int k=20;k>=0;k--)
		{
			if(x->link[k] && x->link[k]->len>=cr-cl) x=x->link[k];
		}
		queries[x->id].push_back(mp(i,mp(l,r)));
	}
	dfs(0);
	for(int i=0;i<q;i++)
	{
		printf("%d %d\n",res[i].id+1,res[i].cnt);
	}
	return 0;
}