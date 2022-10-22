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
#define endout fflush(stdout)
const int N=110;
int n;
#define pi pair<int,int>
#define fi first
#define se second
queue<pi> q[2];
signed main(){
	n=read();For(i,1,n)For(j,1,n)q[i+j&1].push(pi(i,j));
	For(i,1,n*n){
		int a=read();
		if(a==3){
			if(!q[0].empty()){
				pi p=q[0].front();q[0].pop();
				printf("%d %d %d\n",1,p.fi,p.se);
				endout;
				continue;
			}if(!q[1].empty()){
				pi p=q[1].front();q[1].pop();
				printf("%d %d %d\n",2,p.fi,p.se);
				endout;
				continue;
			}assert(0);
		}if(a==2){
			if(!q[0].empty()){
				pi p=q[0].front();q[0].pop();
				printf("%d %d %d\n",1,p.fi,p.se);
				endout;
				continue;
			}else{
				pi p=q[1].front();q[1].pop();
				printf("%d %d %d\n",3,p.fi,p.se);
				endout;
				continue;
			}
		}if(a==1){
			if(!q[1].empty()){
				pi p=q[1].front();q[1].pop();
				printf("%d %d %d\n",2,p.fi,p.se);
				endout;
				continue;
			}else{
				pi p=q[0].front();q[0].pop();
				printf("%d %d %d\n",3,p.fi,p.se);
				endout;
				continue;
			}
		}
	}
	return 0;
}