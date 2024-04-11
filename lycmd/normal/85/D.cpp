#include<bits/stdc++.h>
#define int long long
using namespace std;
mt19937 rnd(114514);
struct treap{
	static int const N=233333;
	int tot,rt,a[N],sz[N],ls[N],rs[N],tr[N],s[N][5],val[N];
	void update(int x){
		sz[0]=0;
		sz[x]=sz[ls[x]]+sz[rs[x]]+1;
		memset(s[0],0,sizeof s[0]);
		for(int i=0;i<5;i++)
			s[x][i]=s[ls[x]][i]+s[rs[x]][(i-sz[ls[x]]%5+4)%5];
		s[x][(sz[ls[x]]+1)%5]+=tr[x];
	}
	void lrotate(int&x){
		int y=rs[x];
		rs[x]=ls[y],ls[y]=x,sz[y]=sz[x];
		update(x),x=y;
	}
	void rrotate(int&x){
		int y=ls[x];
		ls[x]=rs[y],rs[y]=x,sz[y]=sz[x];
		update(x),x=y;
	}
	void insert(int&x,int k){
		if(!x){
			x=++tot,sz[x]=1,tr[x]=s[x][1]=k,val[x]=rnd();
			return;
		}
		sz[x]++;
		if(k<tr[x])
			insert(ls[x],k);
		else
			insert(rs[x],k);
		if(ls[x]&&val[x]>val[ls[x]])
			rrotate(x);
		if(rs[x]&&val[x]>val[rs[x]])
			lrotate(x);
		update(x);
	}
	void erase(int&x,int k){
		sz[x]--;
		if(tr[x]==k){
			if(!ls[x])x=rs[x];
			else if(!rs[x])x=ls[x];
			else if(val[ls[x]]<val[rs[x]])
				rrotate(x),erase(rs[x],k);
			else
				lrotate(x),erase(ls[x],k);
			update(x);
			return;
		}
		if(tr[x]>=k)
			erase(ls[x],k);
		else
			erase(rs[x],k);
		update(x);
	}
};
int q;
treap t;
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>q;q--;){
		string op;int x;cin>>op;
		switch(op[0]){
			case'a':cin>>x,t.insert(t.rt,x);break;
			case'd':cin>>x,t.erase(t.rt,x);break;
			case's':cout<<t.s[t.rt][3]<<"\n";break;
		}
	}
}