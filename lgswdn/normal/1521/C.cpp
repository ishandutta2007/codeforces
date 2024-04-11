#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=2e4+9;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int T,n,m,p[N];

int qry(int t,int i,int j,int x) {
	printf("? %d %d %d %d\n",t,i,j,x);
	fflush(stdout);
	int ret=read();
	if(ret==-1) exit(0);
	return ret;
}

int main() {
	T=read();
	while(T--) {
		n=read();
		if(n==-1) return 0;
		rep(i,1,n) p[i]=0;
		vector<int>pn;
		if(n%2==1) pn.push_back(n);
		bool findn=0;
		rep(i,1,n-1) if(i%2==1) {
			int res=qry(1,i,i+1,n-1);
			if(res==n) {
				p[i+1]=n;
				findn=1;
				break;
			} else if(res==n-1) {
				pn.push_back(i);
			}
		}
		if(!findn) {
			for(auto x:pn) {
				int res=qry(2,x,(x==1?2:1),n-1);
				if(res==n) {
					p[x]=n;
					break;
				}
			}
		}
		int pos=0;
		rep(i,1,n) if(p[i]==n) pos=i;
		rep(i,1,n) if(p[i]!=n) {
			p[i]=qry(2,i,pos,1);
		}
		printf("! ");
		rep(i,1,n) printf("%d ",p[i]);
		puts("");
		fflush(stdout);
	}
	return 0;
}