#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=100009;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int q;

int cnt;
struct node {int c[2],sz;} t[N*30];
void ins(int x,int u=0) {
	per(h,27,0) {
		bool p=(1<<h)&x;
		if(!t[u].c[p]) t[u].c[p]=++cnt;
		u=t[u].c[p];
		t[u].sz++;
	}
}
void del(int x,int u=0) {
	per(h,27,0) {
		bool p=(1<<h)&x;
		u=t[u].c[p];
		t[u].sz--;
	}
}
int query(int x,int y,int u=0,int ret=0) {
	per(h,27,0) {
		bool px=(1<<h)&x, py=(1<<h)&y;
		if(py) ret+=t[t[u].c[px]].sz;
		if(!t[u].c[px^py]) return ret;
		u=t[u].c[px^py];
	}
	return ret;
}


int main() {
	q=read();
	while(q--) {
		int opt=read(), p=read();
		if(opt==1) ins(p);
		else if(opt==2) del(p);
		else printf("%d\n",query(p,read()));
	}
	return 0;
}