// Problem: CF623B Array GCD
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF623B
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 2022-10-09 20:42:45
// Author : louhao088
// 
// Powered by CP Editor (https://cpeditor.org)

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
const int maxn=2e6+5,M=2e5+5,mod=998244353,inf=1e16;
inline int read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1){x=-x;}return x;
}
void print(int x){
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,a,b,v[maxn],f[maxn][3],c[maxn],res;
int solve(int x){
	for(int i=1;i<=n;i++){
		if(v[i]%x==0)c[i]=0;
		else if((v[i]+1)%x==0||(v[i]-1)%x==0)c[i]=b;
		else c[i]=inf;
	}
	for(int i=1;i<=n;i++){
		f[i][0]=min(inf,f[i-1][0]+c[i]);
		f[i][1]=min(inf,min(f[i-1][0],f[i-1][1])+a);
		f[i][2]=min(inf,min(f[i-1][2],f[i-1][1])+c[i]);
	}return min(f[n][0],min(f[n][1],f[n][2]));
}
void get(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			res=min(res,solve(i));
			while(x%i==0)x=x/i;
		}
	}
	if(x!=1)res=min(res,solve(x));
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),a=read(),b=read();
	for(int i=1;i<=n;i++)v[i]=read();
	res=inf;
	get(v[1]),get(v[n]);
	get(v[1]-1),get(v[n]-1);
	get(v[1]+1),get(v[n]+1);
	cout<<res<<endl;
 	return 0;
}