#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define endout fflush(stdout)
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=510;
struct node{
	int v,id;
	bool operator < (const node &x) const {
		return v<x.v;
	}
};priority_queue<node> q;
node stk[N];int tp;
int a[N],t[N];
signed main(){
	int n=read(),k=read();
	if(n%2==1&&k%2==0){puts("-1"),endout;return 0;}
	int x=0;
	For(i,1,n)t[i]=1;int sum=n;
	while(sum%k){
		For(i,1,n){
			if(sum%k==0&&t[1]<=sum/k)break;
			sum+=2,t[i]+=2;
		}
	}
	For(i,1,n)q.push((node){t[i],i});
	while(!q.empty()){
		For(j,1,k)stk[j]=q.top(),q.pop();
		printf("?");
		For(j,1,k){
			printf(" %d",stk[j].id);
			stk[j].v--;
			if(stk[j].v)q.push(stk[j]);
		}cout<<endl;
		x^=read();
	}cout<<"! "<<x<<endl;
	return 0;
}