#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=3e5+9;;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int T,n,m,p[N],q[N],qt[N];
bool ans[N],vst[N];

int main() {
	T=read();
	while(T--) {
		n=read(), m=read();
		rep(i,1,n) p[i]=read();
		rep(i,0,n-1) ans[i]=0;
		rep(rs,1,100) {
			int pos=rand()%n+1,k=0;
			rep(i,0,n-1) {
				int np=(pos+i)%n; if(np==0) np=n;
				if(np==p[pos]) {k=i; break;}
			}
			rep(i,1,n) q[i]=((i+k)%n==0?n:(i+k)%n);
			int tot=0;
			rep(i,1,n) tot+=(p[i]==q[i]);
			if(tot<n-m*2) continue;
			rep(i,1,n) qt[q[i]]=i, vst[i]=0;
			int cnt=0;
			rep(i,1,n) if(!vst[i]) {
				int pos=i,sz=0;
				while(!vst[pos]) sz++, vst[pos]=1, pos=qt[p[pos]];
				cnt+=sz-1;
			}
			if(cnt<=m) ans[(n-k)%n]=1;
		}
		vector<int>fk;
		rep(i,0,n-1) if(ans[i]) fk.push_back(i);
		printf("%d ",(int)fk.size());
		for(auto x:fk) printf("%d ",x);
		puts("");
	}
	return 0;
}