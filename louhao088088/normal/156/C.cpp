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
const int maxn=2e5+5,M=2e5+5,mod=1e9+7;
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
int n,m,f[105][2705],T,sum=0;
char s[maxn];
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	f[0][0]=1;
	for(int i=1;i<=100;i++){
		for(int j=i-1;j<=(i-1)*26;j++)if(f[i-1][j]){
			for(int k=1;k<=26;k++)f[i][j+k]=(f[i-1][j]+f[i][j+k])%mod;
		}
	}
	T=read();
	while(T--){
		scanf("%s",s+1);n=strlen(s+1);sum=0;
		for(int i=1;i<=n;i++)sum+=s[i]-'a'+1;
		printf("%lld\n",(f[n][sum]-1+mod)%mod);
	}
 	return 0;
}