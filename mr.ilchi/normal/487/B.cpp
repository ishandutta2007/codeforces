#include <bits/stdc++.h>
using namespace std;

const int MAXN= 100000;
const int MAXT = 1<<18;
const int inf = 2000000001;

int n,s,l;
int mina[MAXT],maxa[MAXT],mindp[MAXT];

int getmin (int *f, int root, int lo, int hi, int l, int r){
	if (r<lo || hi<l)
		return inf;
	if (l<=lo && hi<=r)
		return f[root];
	int mid = (lo + hi)/2;
	return min(getmin(f,root*2,lo,mid,l,r), getmin(f,root*2+1,mid+1,hi,l,r));
}

int getmax(int *f, int root, int lo, int hi, int l, int r){
	if (r<lo || hi<l)
		return -inf;
	if (l<=lo && hi<=r)
		return f[root];
	int mid = (lo + hi)/2;
	return max(getmax(f,root*2,lo,mid,l,r), getmax(f,root*2+1,mid+1,hi,l,r));
}

void gomin (int *f, int root, int lo, int hi, int pos, int val){
	if (lo == hi){
		f[root] = val;
		return;
	}
	int mid = (lo + hi)/2;
	if (pos <= mid)
		gomin(f,root*2,lo,mid,pos,val);
	else
		gomin(f,root*2+1,mid+1,hi,pos,val);
	f[root] = min(f[root*2], f[root*2+1]);
}

void gomax (int *f, int root, int lo, int hi, int pos, int val){
	if (lo == hi){
		f[root] = val;
		return;
	}
	int mid = (lo + hi)/2;
	if (pos <= mid)
		gomax(f,root*2,lo,mid,pos,val);
	else
		gomax(f,root*2+1,mid+1,hi,pos,val);
	f[root] = max(f[root*2], f[root*2+1]);
}

int main(){
	cin >> n >> s >> l;
	for (int i=0; i<MAXT; i++){
		maxa[i] = -inf;
		mina[i] = inf;
		mindp[i]= inf;
	}
	for (int i=0; i<n; i++){
		int a; cin >> a;
		gomin(mina, 1, 0, n-1, i, a);
		gomax(maxa, 1, 0, n-1, i, a);
	}
	for (int i=l-1; i<n; i++){
		int lo=0,hi=i-l+1,ans=i;
		while (lo<=hi){
			int mid = (lo + hi)/2;
			int xmin = getmin(mina, 1, 0, n-1, mid, i);
			int xmax = getmax(maxa, 1, 0, n-1, mid, i);
			if (xmax-xmin <= s){
				ans = mid;
				hi = mid-1;
			}else
				lo = mid+1;
		}
		if (ans>i-l+1)
			continue;
		lo = ans;
		hi = i-l+1;
		if (ans==0 || lo <= hi){
			int temp = (ans==0 ? 1 : getmin(mindp, 1, 0, n-1, lo-1, hi-1) + 1);
			gomin(mindp, 1, 0, n-1, i, temp);
		}
	}
	int ans = getmin(mindp, 1, 0, n-1, n-1, n-1);
	if (ans == inf)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}