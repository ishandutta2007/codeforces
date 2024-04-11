#include <bits/stdc++.h>
using namespace std;

int n,m;
int s[64],v[64],w[64],q[64];


int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		int l;
		scanf("%d",&l);		
		s[i]=v[i]=0;
		w[i]=-1005;
		q[i]=-1005;
		while(l--){
			int k;
			scanf("%d",&k);
			s[i]+=k;
			q[i]=max(q[i],s[i]-v[i]);
			v[i]=min(v[i],s[i]);
			w[i]=max(w[i],s[i]);
		}
	}
	long long r=-1005,t=0,x=0;
	while(m--){
		int k;
		scanf("%d",&k);
		r=max(r,1LL*q[k]);
		r=max(r,t+w[k]-x);
		x=min(x,t+v[k]);
		t+=s[k];
	}
	cout<<r<<endl;
	return 0;
}