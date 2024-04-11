#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
typedef pair<int,int> pii;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,m,cnt1,cnt2;
map<pii,char>e;
char op[3],cc[3];

int main() {
	n=read(), m=read();
	while(m--) {
		scanf("%s",op); char opt=op[0];
		if(opt=='?') {
			int k=read();
			if(k%2) puts(cnt1?"YES":"NO");
			else puts(cnt2?"YES":"NO");
		} else if(opt=='+') {
			int u=read(), v=read(); scanf("%s",cc); char c=cc[0];
			if(e[pii(v,u)]) cnt1++;
			if(e[pii(v,u)]==c) cnt2++;
			e[pii(u,v)]=c;
		} else {
			int u=read(), v=read();
			if(e[pii(v,u)]) cnt1--;
			if(e[pii(v,u)]==e[pii(u,v)]) cnt2--;
			e[pii(u,v)]=0; 
		}
	}
	return 0;
}