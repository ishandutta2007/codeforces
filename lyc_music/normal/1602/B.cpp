#include<iostream>
using namespace std;
int n,pos;
int a[2005][2005],t[2005];
inline bool check() {
	if(pos==0) return 0;
	for(int i=1;i<=n;i++)
		if(a[pos][i]!=a[pos-1][i]) return 0;
	return 1;
}
int main() {
	int T,q;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(int i=1; i<=n; i++) scanf("%d",&a[0][i]);
		pos=0;
		while(!check()) {
			for(int i=1;i<=n;i++) t[i]=0;
			for(int i=1;i<=n;i++) t[a[pos][i]]++;
			pos++;
			for(int i=1;i<=n;i++) a[pos][i]=t[a[pos-1][i]];
		}
		scanf("%d",&q);
		while(q--) {
			int x,k;
			scanf("%d%d",&x,&k);
			k=min(k,pos);
			cout<<a[k][x]<<'\n';
		}
	}
	return 0;
}