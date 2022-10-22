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
const int N=1e6+10;
int n,a[N];
bitset<N> st;
int pr[N],cnt,mn[N];
void get(int n=N-10){
	for(int i=2;i<=n;i++){
	    if(!st[i])pr[++cnt]=i,mn[i]=i;
	    for(int j=1;j<=cnt&&i*pr[j]<=n;j++){
	      	st[i*pr[j]]=1;
	      	if(i%pr[j]==0){
	      		mn[i*pr[j]]=mn[i];
			  	break;
			}mn[i*pr[j]]=pr[j];
	    }
	}
}
int b[N];
int to(int x){
	int ret=1;
	while(x>1){
		int p=mn[x],c=0;
		while(x%p==0)x/=p,c^=1;
		if(c)ret*=p;
	}return ret;
}
signed main(){
	get();
	int T=read();while(T--){
		For(i,1,n=read())b[a[i]=to(read())]++;
		sort(a+1,a+1+n);int ans1=0,ans2=1;
		For(i,1,n)if(a[i]!=a[i-1]){
			int v=b[a[i]];
			if(a[i]==1&&(v&1))ans1+=v;
			if(v&1)ans2=max(ans2,v);
			else ans1+=v,ans2=max(ans2,v);
		}
		For(i,1,n)b[a[i]]--;
		int q=read();while(q--){
			int w=read();if(!w)printf("%lld\n",ans2);
			else printf("%lld\n",max(ans1,ans2));
		}
	}
	return 0;
}