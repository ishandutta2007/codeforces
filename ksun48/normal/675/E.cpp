#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int l[2200000];
int r[2200000];
int val[2200000];
int p[2200000];
int n, m;
void build(int i, int a, int b){
	l[i] = a;
	r[i] = b;
	if(l[i] == r[i]){
		val[i] = l[i];
	} else {
		build(2*i+1, a, (a+b)/2);
		build(2*i+2, (a+b)/2+1, b);
		if(p[val[2*i+2]] >= p[val[2*i+1]]){
			val[i] = val[2*i+2];
		} else {
			val[i] = val[2*i+1];
		}
	}
}
int q(int i, int a, int b){
	if(l[i] == a && r[i] == b){
		return val[i];
	}
	if(b <= r[2*i+1]) return q(2*i+1,a,b);
	if(a >= l[2*i+2]) return q(2*i+2,a,b);
	int c = q(2*i+1,a,r[2*i+1]);
	int d = q(2*i+2,l[2*i+2],b);
	if(p[c] >= p[d]) return c;
	return d;
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		scanf("%d", &p[i]);
	}
	p[n] = n;
	build(0,1,n);
	LL cnt[n];
	LL ans = 0;
	for(int i = 1; i < n; i++){
		cnt[i] = 1;
	}
	for(int i = 1; i < n; i++){
		ans += (LL)(n-i);
		ans += ((LL)(n-p[i]))*cnt[i];
		int e = q(0,i+1,p[i]);
		if(e < n) cnt[e] += cnt[i];
	}
	cout << ans << endl;
}