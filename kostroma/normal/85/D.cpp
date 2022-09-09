#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
typedef pair <li, li> pli;
typedef vector <int> vi;
typedef vector <li> vli;
#define mp make_pair
#define pb push_back
void solve ();
int main ()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
#endif
	int t=1;
	while (t--)
		solve ();
	return 0;
}
//caution: is int really int?
//#define int li
struct treap
{
	typedef struct _node
{
	int v, y, cnt;
	li sums[5];
	_node *l, *r;
	_node (int X):v(X), cnt(1), l(0), r(0) { y=(rand()<<16)|rand(); memset (sums, 0, sizeof (sums)); sums[0]=v; }
	void recalc()
	{
		cnt=0;
		memset (sums, 0, sizeof sums);
		if (l)
		{
			for ( int i=0; i<5; i++ )
				sums[(i+cnt)%5]+=l->sums[i];
			cnt+=l->cnt;
		}
		sums[cnt++ %5]+=v;
		if (r)
		{
			for ( int i=0; i<5; i++ )
				sums[(i+cnt)%5]+=r->sums[i];
			cnt+=r->cnt;
		}
	}
}*node;
	node root;
	node merge ( node l, node r )
	{
		if (!l)
			return r;
		if (!r)
			return l;
		if ( l->y < r->y )
		{
			l->r=merge ( l->r, r );		
			l->recalc();
			return l;
		}
		else 
		{
			r->l=merge (l, r->l);
			r->recalc();
			return r;
		}
	}
	void split ( node v, int key, node &l, node &r )
	{
		l=r=0;
		if (!v)
			return;
		node tmp;
		if (v->v < key)
		{
			l=v;
			split (l->r, key, tmp, r);
			l->r=tmp;
			l->recalc();
		}
		else 
		{
			r=v;
			split (r->l, key, l, tmp);
			r->l=tmp;
			r->recalc();
		}
	}
	treap() : root (0) {}
	void insert (int x)
	{
		node l, r;
		split (root, x, l, r);
		root=merge ( merge (l, new _node(x)), r );
	}
	void erase (int x)
	{
		node l, m1, m2, r;
		split (root, x, l, m1);
		split (m1, x+1, m2, r);
		if ( m2 ) { delete m2; m2=0; }
		root=merge (l, r);
	}
	li get (int mod)
	{
		if (!root)
			return 0;
		return root->sums[mod%5];
	}
};
int num;
string s;
void solve ()
{
	cin>>num;
	treap tree;
	for ( int i=0; i<num; i++ )
	{
		cin>>s;
		if (s[0]=='s')
		{
			
			printf ("%I64d\n", tree.get(2));
			continue;
		}
		int n;
		scanf ("%d", &n);
		if ( s[0]=='d' )
		{
			tree.erase(n);
			continue;
		}
		if (s[0]=='a')
		{
			tree.insert(n);
			continue;
		}
	}
}