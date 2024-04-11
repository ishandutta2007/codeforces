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
#define inf 1000000100
int n,k;
int a[333333],dp[333333];

int seg[333333*4];
void upd(int i,int s,int e,int x,int y){
	if(s == x && e == x){
		seg[i] = y;
		return;
	}
	int m = (s + e)/2;
	if(x <= m)upd(i*2, s, m, x, y);else
		upd(i*2+1,m+1,e,x,y);
	seg[i] = min(seg[i*2],seg[i*2+1]);
}
int query(int i,int s,int e,int l,int r){
	if(l > r)return inf;
	if(s==l && e==r)return seg[i];
	int m=(s+e)/2;
	if(r<=m)return query(i*2,s,m,l,r);
	if(l>m)return query(i*2+1,m+1,e,l,r);
	return min(query(i*2,s,m,l,m),query(i*2+1,m+1,e,m+1,r));
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=0; i<k; i++){
		dp[i] = i==0?0:inf;
		upd(1,0,n,i,dp[i]);
	}
	for(int i=k; i<=n; i++){
		int lo = 0, hi = inf;
		while(lo != hi){
			int mi = (lo+hi)/2;
			
			int L=1, R=i;
			while(L != R){
				int M = (L+R)/2;
				if(a[i] - a[M] <= mi)
					R = M;
				else
					L = M+1;
			}

			if(query(1,0,n,L-1,i-k) <= mi)
				hi = mi;
			else
				lo = mi+1;
		}
		upd(1,0,n,i,dp[i]=lo);
	}
	printf("%d\n",dp[n]);
	return 0;
}