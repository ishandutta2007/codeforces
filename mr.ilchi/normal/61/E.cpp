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

typedef long long ll;

const int maxT= (1<<21) + 5;
const int maxN= 1000000+5;

int n;
int a[maxN], pos[maxN];
ll sum[maxT], inv[maxT];

struct node{
	int s,e;

	node (int _s=-1, int _e=-1) : s(_s), e(_e) {}

}t[maxT];
/*************************************/
inline bool cmp (const int &a1, const int &a2){
	return a[a1]<a[a2];
}
/*************************************/
inline void settree (int root){
	if (t[root].s==t[root].e)
		return;
	
	int mid= (t[root].s + t[root].e)/2;
	t[root<<1]= node (t[root].s, mid);
	t[(root<<1)+1]= node (mid+1, t[root].e);
	settree (root<<1); settree ((root<<1)+1);
}
/*************************************/
inline int findSum (int root, int s, int e){
	node &tmp= t[root];
	if (tmp.e<s || e<tmp.s)
		return 0;
	if (s<=tmp.s && tmp.e<=e)
		return sum[root];

	return findSum ((root<<1), s, e) + findSum ((root<<1)+1, s, e);
}
/*************************************/
inline void add (int root, int pla){
	sum[root] ++;
	if (t[root].s == t[root].e)
		return;
	if (pla<=t[root<<1].e)
		add ((root<<1), pla);
	else
		add ((root<<1)+1, pla);
}
/*************************************/
inline ll findInv (int root, int s, int e){
	node &tmp= t[root];
	if (tmp.e<s || e<tmp.s)
		return 0;
	if (s<=tmp.s && tmp.e<=e)
		return inv[root];

	return findInv ((root<<1), s, e) + findInv ((root<<1)+1, s, e);
}
/*************************************/
inline void addInv (int root, int pla, int cost){
	inv[root]+= cost;

	if (t[root].s == t[root].e)
		return;
	
	if (pla<=t[root<<1].e)
		addInv (root<<1, pla, cost);

	else
		addInv ((root<<1)+1, pla, cost);
}
/*************************************/
int main(){
	scanf ("%d", &n);
	for (int i=1;i<=n;i ++){
		scanf ("%d", &a[i]); pos[i]=i;
	}
	sort (pos+1, pos+n+1, cmp);
	for (int i=1;i<=n;i ++)
		a[pos[i]]= i;

	t[1].s=1, t[1].e= n;
	settree (1);

	ll res=0;
	for (int i=n;i>0;i --){
		int tmp= findSum (1, 1, a[i]);
		res+= findInv (1, 1, a[i]);
		add (1, a[i]); addInv (1, a[i], tmp);
	}
		
	printf ("%I64d\n", res);

	return 0;
}