#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=(int)(0);N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

struct Node{
	int a[3][3];
};
Node operator+(Node a,Node b){
	Node ans;
	F(i,0,2)F(j,i,2)ans.a[i][j]=1e9;
	F(i,0,2)F(j,i,2)F(k,i,j)ans.a[i][j]=min(ans.a[i][j],a.a[i][k]+b.a[k][j]);
	return ans;
}
Node g(int c){
	Node ans;
	F(i,0,2){
		F(j,i,2)ans.a[i][j]=1e9;
		ans.a[i][i]=i==c;
		if(i!=2)ans.a[i][i+1]=i!=c;
	}
	return ans;
}

const int N=1.1e5;

struct SegTree{
	Node val[N*4];
	void upd(int id){
		val[id]=val[id<<1]+val[id<<1|1];
	}
	int query()const{
		return *min_element(val[1].a[0],val[1].a[0]+3);
	}
	void edit(int x,char c,int ll,int rr,int id){
		if(ll==rr){
			val[id]=g(c-'a');
		}
		else{
			int mid=(ll+rr)>>1;
			if(x<=mid)edit(x,c,ll,mid,id<<1);
			else edit(x,c,mid+1,rr,id<<1|1);
			upd(id);
		}
	}
}tr;

char s[N];

int main(){
	int n=read(),q=read();
	scanf("%s",s+1);
	F(i,1,n){
		tr.edit(i,s[i],1,n,1);
	}
	D(_,q){
		int x=read();
		char tmp[10];
		scanf("%s",tmp);
		tr.edit(x,tmp[0],1,n,1);
		int ans=tr.query();
		printf("%d\n",ans);
	}
	return 0;
}