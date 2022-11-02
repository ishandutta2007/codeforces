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
const int maxn=3e6+5,M=2e5+5,mod=1e9+7;
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
int n,k,a[maxn],f[maxn],mn,mx,s[maxn];
bool check(int x){
	int res=0;
	for(int i=x;i<=mx;i+=x)res+=s[i+k]-s[i-1];
	if(res>=n)return 1;
	return 0;
}
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),k=read();mn=1e9;
	for(int i=1;i<=n;i++)a[i]=read(),mx=max(mx,a[i]),mn=min(mn,a[i]),s[a[i]]++;
	for(int i=1;i<=mx+k;i++)s[i]=s[i-1]+s[i];
	if(mn<=k)cout<<mn<<endl,exit(0);
	for(int i=mn;i>=k;i--){
		if(check(i))cout<<i<<endl,exit(0);
	}
 	return 0;
}