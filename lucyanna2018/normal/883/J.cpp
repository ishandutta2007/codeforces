/*#### bits/stdc++.h */
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<deque>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
/*####*/
int tim, building, n1;

#define int64 long long int 
#define ran 111111
int64 a[ran],maxa[ran];

int64 money_all[ran], sgn[ran];
struct Building{
	int cp;
	int64 cost;
}b[ran];
bool cmp(Building A,Building B){
	return A.cost < B.cost || A.cost == B.cost && A.cp > B.cp;
}

struct segTree{
	int64 add, min;
	void push(int64 x){
		add += x;
		min += x;
	}
} seg[ran * 4];
void push(int i){
	int64&tmp = seg[i].add;
	if(tmp == 0)return;
	seg[i*2].push(tmp);
	seg[i*2+1].push(tmp);
	tmp = 0;
}
void merge(int i){
	seg[i].min = min(seg[i*2].min,seg[i*2+1].min);
}
void build(int i,int s,int e){
	if(s==e){
		seg[i].min = money_all[s];
		return;
	}
	int m=(s+e)/2;
	build(i*2,s,m);
	build(i*2+1,m+1,e);
	merge(i);
}
int64 query(int i,int s,int e,int l,int r){
	if(s==l && e==r){
		return seg[i].min;
	}
	push(i);
	int m=(s+e)/2;
	if(r<=m)return query(i*2,s,m,l,r);
	if(l>m)return query(i*2+1,m+1,e,l,r);
	return min(query(i*2,s,m,l,m),query(i*2+1,m+1,e,m+1,r));
}
void upd(int i,int s,int e,int l,int r,int64 x){
	if(s==l && e==r){
		seg[i].push(x);
		return;
	}
	push(i);
	int m=(s+e)/2;
	if(r<=m)upd(i*2,s,m,l,r,x);else
		if(l>m)upd(i*2+1,m+1,e,l,r,x);else{
			upd(i*2,s,m,l,m,x);
			upd(i*2+1,m+1,e,m+1,r,x);
		}
	merge(i);
}

int main(){
	scanf("%d%d",&n1,&building);
	for(int i=1; i<=n1; i++)
		scanf("%I64d",&a[i]);
	for(int i=n1; i>=1; i--)
		maxa[i] = max(maxa[i+1], a[i]);
	int64 tot = 0;
	for(int i=1; i<=n1; i++){
		tot += a[i];
		if(a[i] > maxa[i+1]){
			++tim;
			money_all[tim] = tot;
			sgn[tim] = -a[i];
		}
	}
	for(int i=1; i<=building; i++){
		int64 x;
		scanf("%I64d",&x);
		b[i].cp = upper_bound(sgn+1, sgn+tim+1, -x) - sgn - 1;
	}
	for(int i=1; i<=building; i++)
		scanf("%I64d",&b[i].cost);
	sort(b+1, b+building+1, cmp);
	build(1, 0, tim);
	int res = 0;
	for(int i=1; i<=building; i++){
		if(b[i].cost <= query(1, 0, tim, b[i].cp, tim)){
			res++;
			upd(1, 0, tim, b[i].cp, tim, -b[i].cost);
		}
	}
	printf("%d\n",res);
	return 0;
}