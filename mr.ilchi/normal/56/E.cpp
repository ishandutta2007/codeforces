/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

const int MAXN= 100*1000+5;
const int MAXL= (1<<20) +5;
const int INF = -(1000*1000*1000);

int n;
int dp [MAXN], pla[MAXN];
int x [MAXN], h[MAXN];
int par[MAXL];

struct domino{
	int id, val;

	domino (int _id= 0, int _val= INF) : id(_id), val(_val) {}

	inline bool operator <  (const domino &sec) const{
		return x[id]< x[sec.id];
	}

}a[MAXN];	
/********************************************/
struct node{
	int s, e;

	node (int _s= -1, int _e= -1) : s(_s), e(_e) {}

}b[MAXL];
/********************************************/
inline void setTree (int id){
	if (b[id].s== b[id].e)
		return;
	int mid= ((b[id].s+b[id].e)>>1);
	int child= (id<<1);
	b[child].s= b[id].s, b[child].e= mid;
	child ++;
	b[child].s= mid+1, b[child].e= b[id].e;
	setTree (child-1);
	setTree (child);
}
/********************************************/
inline int find_max (int root, int beg, int fin){
	if (b[root].e < beg || fin < b[root].s)
		return 0;
	if (beg<= b[root].s && b[root].e<= fin)
		return par[root];
	
	int l= find_max ((root<<1), beg, fin);
	int r= find_max ((root<<1)+1,beg,fin);
	return (a[l].val < a[r].val) ? r : l;
}
/********************************************/
inline void add (int root, int p){
	if (a[par[root]].val < a[p].val)
		par[root]= p;

	if (b[root].s== b[root].e)
		return;

	int mid= ((b[root].s+b[root].e)>>1);
	int Left= (root<<1);
	(p<= mid) ? (add(Left, p)) : (add (Left+1, p));
}
/********************************************/
int main (){
	scanf ("%d", &n);
	for (int i= 1;i<= n;i ++){
		scanf ("%d%d", &x[i], &h[i]);
		a[i].id= i;
		a[i].val= x[i]+h[i]-1;
	}
	sort (a+1, a+n+1);
	for (int i= 1;i<= n;i ++)
		pla[a[i].id]= i;
	
	b[1].s= 1, b[1].e= n;
	setTree (1);

	for (int i= n;i>= 1;i --){
		int cur= a[i].id;
		x[0]= a[i].val;
		domino *p= upper_bound (a+i+1, a+n+1, domino (0, 0));
		int len= (p-a)-i;
		if (p== &a[n+1])
			dp[cur]= len;
		else{
			int tmp= a [find_max (1, i+1, p-a-1)].id;
			dp[cur]= max (dp[tmp]+ pla[tmp]-i, len);
		}
		add (1, i);
	}	
	for (int i= 1;i<= n;i ++)
		printf ("%d ", dp[i]);
	printf ("\n");

	return 0;
}