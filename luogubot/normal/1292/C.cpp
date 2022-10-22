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
const int N=3e3+10;
int n;
int head[N],to[N<<1],nxt[N<<1],val[N<<1],cnt;
void add(int u,int v,int w){
	to[++cnt]=v,val[cnt]=w,nxt[cnt]=head[u],head[u]=cnt;
}int U[N],V[N],S[N],used[N],ans;
int sz;void dfs(int u,int f){
	sz++;go(u)if(to[i]!=f)dfs(to[i],u);
}int dis[N][N];
void get(int u,int f,int* d){
	go(u)if(to[i]!=f)d[to[i]]=d[u]+1,get(to[i],u,d);
}
#define pi pair<int,int>
#define fi first
#define se second
queue<pi> q;int f[N][N],s1[N][N],s2[N][N];
signed main(){
	For(i,2,n=read()){
		int u=read(),v=read();
		U[i]=u,V[i]=v;add(u,v,i),add(v,u,i);
	}For(i,2,n)sz=0,dfs(V[i],U[i]),S[i]=sz,q.push(pi(U[i],V[i])),f[U[i]][V[i]]=S[i]*(n-S[i]),s1[U[i]][V[i]]=n-S[i],s2[U[i]][V[i]]=S[i];
	For(i,1,n)get(i,0,dis[i]);while(!q.empty()){
		int u=q.front().fi,v=q.front().se,W=f[u][v];q.pop();
		ans=max(ans,f[u][v]);int S1=s1[u][v],S2=s2[u][v];
//		printf("f[%d][%d] = %d\n",u,v,W);
		go(u){
			int w=to[i];if(dis[w][v]==dis[u][v]+1){
				int ss=(w==V[val[i]])?S[val[i]]:(n-S[val[i]]);
				if(!f[w][v])q.push(pi(w,v)),s1[w][v]=ss,s2[w][v]=S2;
				if(ss*S2+W>f[w][v])f[w][v]=ss*S2+W;
			}
		}
		go(v){
			int w=to[i];if(dis[u][w]==dis[u][v]+1){
				int ss=(w==V[val[i]])?S[val[i]]:(n-S[val[i]]);
				if(!f[u][w])q.push(pi(u,w)),s1[u][w]=S1,s2[u][w]=ss;
				if(S1*ss+W>f[u][w])f[u][w]=S1*ss+W;
			}
		}
	}cout<<ans<<endl;
//	int j=0;For(i,2,n){
//		if(S[i]*(n-S[i])>S[j]*(n-S[j]))j=i;
//	}
//	used[j]=1,ans=S[j]*(n-S[j]);int l=U[j],r=V[j],s2=S[j],s1=n-S[j];
//	cout<<l<<" "<<r<<" "<<ans<<" "<<s1<<" "<<s2<<endl;
//	For(T,3,n){
//		int mxs1=0,idl=0,ul=0,mxs2=0,idr=0,ur=0;
//		go(l)if(!used[val[i]]){
//			int v=to[i];
//			int S1=(v==V[val[i]])?S[val[i]]:(n-S[val[i]]);
//			if(S1>mxs1)mxs1=S1,idl=val[i],ul=v;
//		}
//		go(r)if(!used[val[i]]){
//			int v=to[i];
//			int S2=(v==V[val[i]])?S[val[i]]:(n-S[val[i]]);
//			if(S2>mxs2)mxs2=S2,idr=val[i],ur=v;
//		}
//		if(!mxs1&&!mxs2)break;
//		if(mxs1*s2>mxs2*s1){
//			ans+=mxs1*s2,s1=mxs1,used[idl]=1,l=ul;
//		}else ans+=s1*mxs2,s2=mxs2,used[idr]=1,r=ur;
////		cout<<l<<" "<<r<<" "<<ans<<" "<<s1<<" "<<s2<<endl;
//	}cout<<ans<<endl;
	return 0;
}//dsas