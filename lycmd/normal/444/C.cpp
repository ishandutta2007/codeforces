#include<bits/stdc++.h>
#define int long long
#define ord(x) ((x)>>8)
#define bl(x) ((x)<<8)
#define br(x) (min((x)<<8|255,n))
using namespace std;
int const N=200010;
int n,q,a[N],flg[N],c[N],w[N],bs[N],bw[N];
void down(int b){
	if(!flg[b])return;
	for(int i=bl(b);i<=br(b);i++)
		a[i]=c[b],w[i]+=bw[b];
	flg[b]=bw[b]=0;
}
void add(int x,int y){
	int b=ord(x);
	down(b);
	int k=a[x]?abs(a[x]-y):0;
	w[x]+=k,bs[b]+=k,a[x]=y;
}
void cov(int b,int y){
	if(flg[b]){
		int k=abs(c[b]-y);
		bs[b]+=(br(b)-bl(b)+1)*k,bw[b]+=k;
	}else{
		for(int i=bl(b);i<=br(b);i++)
			w[i]+=abs(a[i]-y),bs[b]+=abs(a[i]-y);
	}
	flg[b]=1,c[b]=y;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		a[i]=i;
	while(q--){
		int op,l,r,x;
		cin>>op>>l>>r;
		down(ord(l)),down(ord(r));
		if(op<2){
			cin>>x;
			if(ord(l)==ord(r)){
				for(int i=l;i<=r;i++)add(i,x);
				continue;
			}
			for(int i=l;i<=br(ord(l));i++)add(i,x);
			for(int i=bl(ord(r));i<=r;i++)add(i,x);
			for(int i=ord(l)+1;i<ord(r);i++)cov(i,x);
		}else{
			int res=0;
			if(ord(l)==ord(r)){
				for(int i=l;i<=r;i++)res+=w[i];
			}else{
				for(int i=l;i<=br(ord(l));i++)res+=w[i];
				for(int i=bl(ord(r));i<=r;i++)res+=w[i];
				for(int i=ord(l)+1;i<ord(r);i++)res+=bs[i];
			}
			cout<<res<<"\n";
		}
	}
}