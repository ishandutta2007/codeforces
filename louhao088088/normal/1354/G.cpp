// Problem: CF1354G Find a Gift
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1354G
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 2022-09-22 20:45:39
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
const int maxn=2e5+5,M=2e5+5,mod=998244353;
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
mt19937 rnd(time(0));
int n,m,k,x,T;
char s[maxn];
int ask(int l,int r,int L,int R) {
	printf("? %d %d\n",r-l+1,R-L+1);
	for(int i=l;i<=r;i++) printf("%d ",i);cout<<endl;
	for(int i=L;i<=R;i++) printf("%d ",i);
	cout<<endl;fflush(stdout);scanf("%s",s); 
	if(s[0]=='F')return 1;
	if(s[0]=='S')return 2;return 3;
}
void solve(){
	n=read(),k=read();
	for(int i=1;i<=30;i++){
		x=rnd()%(n-1)+2;int y=ask(1,1,x,x);
		if(y==2){cout<<"! 1"<<endl;fflush(stdout);return;}
	}
	for(x=1;x*2<=n;x*=2)if(ask(1,x,x+1,2*x)!=3) break;
	int l=x+1,r=min(2*x,n);
	while(l<r){
		if(ask(l,mid,1,mid-l+1)==3) l=mid+1;
		else r=mid;
	}fflush(stdout);
	printf("! %d\n",l);fflush(stdout);
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T--)solve();
 	return 0;
}