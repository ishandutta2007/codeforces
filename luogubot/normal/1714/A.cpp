#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int ban[24][60];
struct node{
	int h,m;
	void operator ++ (){
		m++;
		if(m==60)m=0,h++;
		if(h==24)h=0;
	}
}t,a;
signed main(){
	int T=read();while(T--){
		int n=read();t.h=read(),t.m=read();
		a.h=0,a.m=0;
		memset(ban,0,sizeof ban);
		For(i,1,n){
			int h=read(),m=read();
			ban[h][m]=1;
		}while(!ban[t.h][t.m]){
			++t,++a;
		}cout<<a.h<<" "<<a.m<<endl;
	}
	return 0;
}