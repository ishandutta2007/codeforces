#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=3e5+10;
int n,m;
struct node{
	int v,i;
	void init(){v=i=0;} 
	void input(int I){i=I;For(j,1,m)v+=j*read();}
	bool operator < (const node &x) const {
		return v<x.v;
	}
}c[N];
int d[N];
signed main(){
	int T=read();while(T--){
		n=read(),m=read();
		For(i,1,n)c[i].init();
		For(i,1,n)c[i].input(i);
		sort(c+1,c+1+n);For(i,1,n)d[i]=c[i].v-c[i-1].v;
		cout<<c[n].i<<" "<<d[n]<<endl;
	}
	return 0;
}