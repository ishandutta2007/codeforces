#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int l[1000000];
int r[1000000];
int a[220000];
int b[220000];
int maxa[1000000];
int minb[1000000];
void build(int v, int lx, int rx){
	l[v] = lx; r[v] = rx;
	if(lx == rx){
		maxa[v] = a[lx];
		minb[v] = b[lx];
	} else {
		build(2*v+1,lx,(lx+rx)/2);
		build(2*v+2,(lx+rx)/2+1,rx);
		maxa[v] = max(maxa[2*v+1],maxa[2*v+2]);
		minb[v] = min(minb[2*v+1],minb[2*v+2]);
	}
}
int maxav(int v, int lx, int rx){
	if(l[v] == lx && r[v] == rx) return maxa[v];
	if(rx <= r[2*v+1]) return maxav(2*v+1,lx,rx);
	if(lx >= l[2*v+2]) return maxav(2*v+2,lx,rx);
	return max(maxav(2*v+1,lx,r[2*v+1]),maxav(2*v+2,l[2*v+2],rx));
}
int minbv(int v, int lx, int rx){
	if(l[v] == lx && r[v] == rx) return minb[v];
	if(rx <= r[2*v+1]) return minbv(2*v+1,lx,rx);
	if(lx >= l[2*v+2]) return minbv(2*v+2,lx,rx);
	return min(minbv(2*v+1,lx,r[2*v+1]),minbv(2*v+2,l[2*v+2],rx));
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < n; i++) scanf("%d", &b[i]);
	build(0,0,n-1);
	LL ans = 0;
	for(int i = 0; i < n; i++){
		int s1 = i-1; //e works
		int e1 = n;
		int s2 = i-1; //s works
		int e2 = n;
		while(s1 + 1 < e1){
			int m1 = (s1+e1)/2;
			if(maxav(0,i,m1) > minbv(0,i,m1)){
				e1 = m1;
			} else {
				s1 = m1;
			}
		}
		while(s2 + 1 < e2){
			int m2 = (s2+e2)/2;
			if(maxav(0,i,m2) < minbv(0,i,m2)){
				s2 = m2;
			} else {
				e2 = m2;
			}
		}
		ans += e1-e2;
	}
	cout << ans << endl;
}