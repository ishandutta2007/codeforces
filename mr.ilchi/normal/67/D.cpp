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
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxN= 1000*1000 + 5;
const int maxT= (1<<21)+5;

int n;
int par[maxN], maxi[maxT];

struct node{
	int s,e;

	node (int _s=-1, int _e=-1) : s(_s), e(_e) {}

}t[maxT];
/*************************************/
inline void settree (int root){
	if (t[root].s==t[root].e)
		return;

	int lef= (root<<1), rig= (root<<1)+1;
	int mid= (t[root].s+t[root].e)/2;

	t[lef]= node (t[root].s, mid);
	t[rig]= node (mid+1, t[root].e);

	settree (lef); settree (rig);
}
/*************************************/
inline int find (int root, int s, int e){
	node &tmp= t[root];

	if (e<tmp.s || tmp.e<s)
		return 0;

	if (s<=tmp.s && tmp.e<=e)
		return maxi[root];

	int lef= (root<<1), rig= (root<<1)+1;

	return max (find (lef,s,e), find(rig,s,e));
}
/*************************************/
inline void add (int root, int pos, int var){
	maxi[root]= max (maxi[root], var);
	if (t[root].s==t[root].e)
		return;

	int lef= (root<<1);

	if (pos<=t[lef].e)
		add (lef, pos, var);
	else
		add (lef+1, pos, var);
}
/*************************************/
int main(){
	scanf ("%d", &n);
	for (int i=1;i<=n;i++){
		int x;
		scanf ("%d", &x);
		par[x]= i;
	}

	t[1]= node(1,n);

	settree (1);

	int res=1;

	for (int i=1;i<=n;i++){
		int y; scanf ("%d", &y);
		int dp= find (1,par[y]+1,n) + 1;
		add (1,par[y],dp);
		res= max (res,dp);
	}

	printf ("%d\n", res);

	return 0;
}