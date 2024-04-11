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
const int N=5e3+10,M=1e3+10;
int n,g[N][M],t[N],id[N],ok[N],all[N];
int m=5e3;
bitset<N> st;
int pr[N],cnt;
void get(int n=N-10){
	for(int i=2;i<=n;i++){
	    if(!st[i])pr[++cnt]=i,id[i]=cnt;
	    for(int j=1;j<=cnt&&i*pr[j]<=n;j++){
	      	st[i*pr[j]]=1;
	      	if(i%pr[j]==0)break;
	    }
	}
}
int calc(int j){
	int c=0;
	For(i,0,m)if(!ok[i]){
		if(g[i][j+1]||!g[i][j])c+=t[i]; 
	}return c;
}
void work(int j){
	For(i,0,m)if(!ok[i]){
		if(g[i][j+1]||!g[i][j])ok[i]=1;
		else g[i][j]--;
	}
}
signed main(){
	For(i,1,n=read())t[read()]++;
	Rof(i,5e3,0)if(t[i]){m=i;break;}
	get(m); 
	For(i,2,m){
		int x=i;for(int d=2;d*d<=x;d++)while(x%d==0)x/=d,g[i][id[d]]++;
		if(x>1)g[i][id[x]]++;
		For(j,1,cnt)g[i][j]+=g[i-1][j],all[i]+=g[i][j]; 
	}int now=cnt,x=n,ans=0;For(i,1,m)ans+=t[i]*all[i];
	while(1){
		int del=0,val=0,nx=0; 
		Rof(i,now,1){
			int y=x-calc(i);
			if(y-(n-y)>del)del=y-(n-y),val=i,nx=y;
		}if(!val)break;work(val),now=val,ans-=del,x=nx; 
	}cout<<ans<<endl;
	return 0;
}//fasdsa