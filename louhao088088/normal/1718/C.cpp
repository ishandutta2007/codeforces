#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&-x)
#define int long long
const int maxn=2e5+5,M=34005;
inline int read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x){
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,a[maxn],b[maxn],g[maxn],cnt=0,x,y,T;
int f[11][maxn];
struct A{
		priority_queue<int>q1,q2;
		void push(int x){q1.push(x);}
		void pop(){while(!q2.empty()&&q1.top()==q2.top())q1.pop(),q2.pop();q1.pop();}
		int top(){while(!q2.empty()&&q1.top()==q2.top())q1.pop(),q2.pop();return q1.top();}
		void del(int x){q2.push(x);}
		void clear(){while(!q1.empty())q1.pop();while(!q2.empty())q2.pop();}
}Q;
void solve(){
	n=read();m=read();cnt=0;int x=n;Q.clear();
	for(int i=1;i<=n;i++){a[i]=read();}
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			g[++cnt]=i;
			while(x%i==0)x=x/i;
		}
	}if(x>1){g[++cnt]=x;}
	for(int i=1;i<=cnt;i++)for(int j=0;j<=n;j++)f[i][j]=0;
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<=n;j++){
			f[i][j%(n/g[i])]+=a[j];
		}
	}
	for(int i=1;i<=cnt;i++){
		for(int j=0;j<(n/g[i]);j++)Q.push(f[i][j]*n/g[i]);
	}
	printf("%lld\n",Q.top());
	for(int i=1;i<=m;i++){
		x=read(),y=read();
		for(int j=1;j<=cnt;j++){
			int u=x%(n/g[j]);
			Q.del(f[j][u]*n/g[j]);
			f[j][u]-=a[x];f[j][u]+=y;
			Q.push(f[j][u]*n/g[j]);
		}a[x]=y;
		printf("%lld\n",Q.top());
	}
} 
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T--)solve();
 	return 0;
}