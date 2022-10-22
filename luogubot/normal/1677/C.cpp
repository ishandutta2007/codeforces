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
const int N=1e5+10;
int n,a[N],b[N],vis[N],sz;vector<int> g[N];
int stk[N],tp,to[N],tmp[N];
void dfs(int u){
	vis[u]=1,sz++;if(!vis[to[u]])dfs(to[u]);
}int p[N];
int brute(){
	int ans=0;
	For(i,1,n)p[i]=i;do{
		int res=0;For(i,1,n)res+=abs(p[i]-p[to[i]]);
		ans=max(ans,res);
	}while(next_permutation(p+1,p+1+n));
	return ans;
}
signed main(){
	srand(time(NULL));
	int TTT=read();while(TTT--){
		n=read();For(i,1,n)a[read()]=i,g[i].clear(),vis[i]=0;tp=0;
		For(i,1,n)to[a[read()]]=i;
		int ans=0;
//		n=10;For(i,1,n)g[i].clear(),vis[i]=0;tp=0;For(i,1,n)to[i]=i;random_shuffle(to+1,to+1+n);
		For(i,1,n)if(!vis[i])sz=0,dfs(i),stk[++tp]=sz;int L=1,R=n;
//		For(i,1,tp)cout<<stk[i]<<" ";puts("done");
		For(i,1,tp)if(stk[i]&1){
			if(stk[i]==1)continue;
			For(x,1,stk[i]>>1)ans+=2*(R--);
			For(x,1,stk[i]>>1)ans-=2*(L++);
		}
		For(i,1,tp)if(!(stk[i]&1)){
			For(j,1,stk[i]){
				if(j&1)tmp[j]=L++;
				else tmp[j]=R--;
			}For(j,2,stk[i])ans+=abs(tmp[j]-tmp[j-1]);ans+=abs(tmp[1]-tmp[stk[i]]);
		}cout<<ans<<endl;
//		int now=brute();
//		fprintf(stderr,"out: %d,ans: %d\n",ans,now);
//		if(now!=ans)system("pause");
	}
	return 0;
}