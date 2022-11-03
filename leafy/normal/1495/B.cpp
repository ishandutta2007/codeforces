#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
const int N=1e5+5;
int n;
int a[N],ans;
int L1[N],L2[N],R1[N],R2[N],pre[N],suf[N];
int main(){
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++){
		L1[i]=L2[i]=i;
		if(i>1) {
			if(a[i-1]<a[i]) L1[i]=L1[i-1];
			else L2[i]=L2[i-1];
		}
	}
	for(int i=n;i>=1;i--){
		R1[i]=R2[i]=i;
		if(i<n){
			if(a[i+1]<a[i]) R1[i]=R1[i+1];
			else R2[i]=R2[i+1];
		}
	}
	for(int i=1;i<=n;i++) pre[i]=max(pre[i-1],max(i-L2[i]+1,R2[i]-i+1));
	for(int i=n;i>=1;i--) suf[i]=max(suf[i+1],max(i-L2[i]+1,R2[i]-i+1));
	/*for(int i=2;i<n;i++){
		int len=max(i-L1[i]+1,R1[i]-i+1);
		int p=max(pre[L1[i]-1],suf[R1[i]+1]);
		if(L1[i]!=i) p=max(L1[i]-L2[L1[i]]+1,p);
		if(R1[i]!=i) p=max(R2[R1[i]]-R1[i]+1,p);
		//cout<<p<<' '<<len<<endl;
		if(p>=len) continue;
		if(len%2==1) ans++;
	}*/
	int mx=0,cnt=0,p=0,q=0;
	for(int i=1;i<=n;i++){
		int l=i-L1[i];
		if(l>mx) mx=l,p=i,q=0;
		else if(l==mx&&i!=p) q=i;
		l=R1[i]-i;
		if(l>mx) mx=l,p=i,q=0;
		else if(l==mx&&i!=p) q=i;
		if(l==mx) cnt++;
	}
	if(q||p-L1[p]!=R1[p]-p) puts("0");
	else printf("%d",(p-L1[p]+1)&1);
	return 0;
}