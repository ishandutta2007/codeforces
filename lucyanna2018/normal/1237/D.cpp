#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int c[111111],n,res[111111];
struct node{
	int min,max;
} a[111111 * 4];
void build(int i,int s,int e){
	if(s == e){
		a[i].min = a[i].max = c[s];
		return;
	}
	int m = (s+e)/2;
	build(i*2,s,m);
	build(i*2+1,m+1,e);
	a[i].min = min(a[i*2].min,a[i*2+1].min);
	a[i].max = max(a[i*2].max,a[i*2+1].max);
}
int qmin(int i,int s,int e,int l,int r){
	if(s == l && e == r)return a[i].min;
	int m = (s + e) / 2;
	if(r <= m)return qmin(i*2,s,m,l,r);
	if(l > m)return qmin(i*2+1,m+1,e,l,r);
	return min(qmin(i*2,s,m,l,m),qmin(i*2+1,m+1,e,m+1,r));
}
int qmax(int i,int s,int e,int l,int r){
	if(s == l && e == r)return a[i].max;
	int m = (s + e) / 2;
	if(r <= m)return qmax(i*2,s,m,l,r);
	if(l > m)return qmax(i*2+1,m+1,e,l,r);
	return max(qmax(i*2,s,m,l,m),qmax(i*2+1,m+1,e,m+1,r));
}

int fnd_rig_max(int bias,int val){// >= val
	int lo = 1, hi = n + 1;
	while(lo != hi){
		int mi = (lo + hi) / 2;
		int mx = 0;
		if(bias + mi < n)mx = max(mx, qmax(1,0,n-1,bias+1, bias + mi));else{
			if(bias +1 < n)mx = max(mx, qmax(1,0,n-1,bias+1, n-1));
			mx = max(mx, qmax(1,0,n-1,0,bias+mi-n));
		}
		if(mx >= val)
			hi = mi;
		else
			lo = mi + 1;
	}
	if(lo == n + 1)return -1;
	return lo;
}
int fnd_rig_min(int bias,int val){// <= val
	int lo = 1, hi = n + 1;
	while(lo != hi){
		int mi = (lo + hi) / 2;
		int mx = 1000000001;
		if(bias + mi < n)mx = min(mx, qmin(1,0,n-1,bias+1, bias + mi));else{
			if(bias +1 < n)mx = min(mx, qmin(1,0,n-1,bias+1, n-1));
			mx = min(mx, qmin(1,0,n-1,0,bias+mi-n));
		}
		if(mx <= val)
			hi = mi;
		else
			lo = mi + 1;
	}
	if(lo == n + 1)return -1;
	return lo;
}

vector<int> e[111111];
void dfs(int x){
	for(auto y : e[x]){
		if (res[x] == -1)res[y] = -1;else
		res[y] = res[x] + (x - y + n) % n;
		dfs(y);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&c[i]);
	}
	build(1,0,n-1);
	for(int i=0; i<n; i++){
		int cnt1 = fnd_rig_max(i,c[i] + 1);
		int cnt2 = fnd_rig_min(i,c[i]%2 ? c[i] / 2 : c[i]/2 - 1);
		if(cnt1 == -1){
			if(cnt2 == -1)
				res[i] = -1;
			else
				res[i] = cnt2;
		}else
		if(cnt2 != -1 && cnt1 > cnt2)
			res[i] = cnt2;
		else{
			res[i] = -2;
			e[(i+cnt1)%n].push_back(i);
		}
	}
	vector<int> rt;
	for(int i=0; i<n; i++)if(res[i] != -2)rt.push_back(i);
	for(auto x : rt)dfs(x);
	for(int i=0; i<n; i++)printf("%d%c",res[i],i<n-1?' ':'\n');
	return 0;
}