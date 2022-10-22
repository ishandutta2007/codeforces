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
const int N=1e5+10,M=5,B=300;
int n,m;
bitset<N> f[N/B],tmp;map<int,int> mp;int tot,vis[N*M];
int id[N*M],idx;vector<int> in[N*M];
struct node{
	int a[5],w;
	void input(){
		For(i,0,m-1){
			int x=read();if(!mp[x])mp[x]=++tot;a[i]=mp[x];
			vis[a[i]]++;
		}w=read();
	}
	void get(){
		For(i,0,m-1){
			int x=a[i];if(id[x])tmp|=f[id[x]];
			else for(auto v:in[x])tmp.set(v);
		}
	}
	void work(int I){
		For(i,0,m-1){
			int x=a[i];
			if(id[x])f[id[x]][I]=1;
			else in[x].push_back(I);
		}
	}
	bool operator < (const node &x) const {return w<x.w;}
}a[N];
bool ED;
signed main(){
//	printf("%.2lf MB\n",abs(&ED-&ST)/1024.0/1024.0);
	n=read(),m=read();For(i,1,n)a[i].input();
	sort(a+1,a+1+n);For(i,1,n*m)if(vis[i]>=B)id[i]=++idx;
	int ans=2e9+1;
	For(i,1,n)a[i].work(i-1);For(i,2,n){
		tmp.reset(),a[i].get(),tmp.flip();
		int j=tmp._Find_first();j++;if(j<=n)ans=min(ans,a[i].w+a[j].w);
	}cout<<(ans<=2e9?ans:-1)<<endl;
	return 0;
}//test114