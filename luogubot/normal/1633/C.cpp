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
const int N=2e5+10;
int k,w,a,hc,dc,hm,dm;
bool check(int hc,int dc,int hm,int dm,int k,int a){
	int t1=(hm+dc-1)/dc,t2=(hc+dm-1)/dm;
	
}
signed main(){
	int T=read();while(T--){
		hc=read(),dc=read();
		hm=read(),dm=read();
		k=read(),w=read(),a=read();
		int fl=0;
		For(i,0,k)fl|=((hc+i*a-1)/dm+1>=(hm-1)/((k-i)*w+dc)+1);
		puts(fl?"Yes":"No");
	}
	return 0;
}