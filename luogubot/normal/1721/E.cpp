#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
bool ST;
string s,t[100010];int rt;
const int N=2e6+10;
struct ACAM{
	int c[N][26],nxt[N],idx,val[N],fa[N];
	int ins(string &t,int r=0){
		int n=t.size();
		For(i,0,n-1){
			int u=t[i]-'a';
			if(!c[r][u])c[r][u]=++idx,assert(idx<N),val[idx]=u,fa[idx]=r;
			r=c[r][u]; 
		}return r;
	}queue<int> q;
	int dep[N];
	void build(){
		For(i,0,25)if(c[0][i])q.push(c[0][i]),dep[c[0][i]]=1;
		while(!q.empty()){
			int u=q.front();q.pop();
			For(i,0,25)if(c[u][i])nxt[c[u][i]]=c[nxt[u]][i],q.push(c[u][i]),dep[c[u][i]]=dep[u]+1;
			else c[u][i]=c[nxt[u]][i];
		}
	}
	void print(string &s,int r){
		int n=s.size();
		For(i,0,n-1){
			int u=s[i]-'a';
			r=c[r][u];
			int v=nxt[r];while(dep[v]>dep[rt]){
				int fl=1,t=v;Rof(j,dep[v],dep[rt]+1){
					if(val[t]!=s[j-dep[rt]-1]-'a'){fl=0;break;}t=fa[t];
				}
				if(fl)break;v=nxt[v];
			}printf("%d ",dep[v]);
		}puts("");
	}
}A;
bool ED;
signed main(){
//	printf("%.2lf\n",abs(&ED-&ST)/1024.0/1024.0);
	cin>>s,rt=A.ins(s);
	int q=read();For(i,1,q){
		cin>>t[i],A.ins(t[i],rt);
	}A.build();For(i,1,q)A.print(t[i],rt);
	return 0;
}