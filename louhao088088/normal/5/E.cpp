// LUOGU_RID: 90745552
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
const int maxn=1e6+5,M=2e5+5,mod=998244353;
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
int n,m,l[maxn],r[maxn],top=0,g[maxn],mx=0,a[maxn],b[maxn],res=0,id;
pi st[maxn];
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){a[i]=read();if(mx<a[i])mx=a[i],id=i;}
	for(int i=1;i<=n;i++)b[i]=a[(id+i-2)%n+1];
	b[n+1]=mx;n++;st[++top]=mp(mx,1);l[1]=1;
	for(int i=2;i<=n;i++){
		while(b[i]>=st[top].fi&&top)top--;
		l[i]=st[top].se;st[++top]=mp(b[i],i);
	}top=0;st[++top]=mp(mx,n);r[n]=0;
	for(int i=n-1;i>=1;i--){
		while(b[i]>st[top].fi&&top)top--;
		if(b[i]==st[top].fi)g[i]=g[st[top].se]+1,top--;
		r[i]=st[top].se;st[++top]=mp(b[i],i);
	}
	for(int i=1;i<=n-1;i++){
		res+=g[i];
		if(b[i]==b[1])res--;
		if(b[i]<b[1]){
			res+=2;
			if(l[i]==1&&r[i]==n)res--;
		}
	}cout<<res<<endl;
 	return 0;
}