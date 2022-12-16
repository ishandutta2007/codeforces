#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
typedef vector<int> V;
LL read(){LL x;scanf("%lld",&x);return x;}

int mod;
int add(int a,int b){return a+b<mod?a+b:a+b-mod;}
void dadd(int &a,int b){a=add(a,b);}
int sub(int a,int b){return a>=b?a-b:a-b+mod;}
void dsub(int &a,int b){a=sub(a,b);}
int mul(int a,int b){return (LL)a*b%mod;}
void dmul(int &a,int b){a=mul(a,b);}
int ksm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)dmul(ans,a);
		b>>=1;
		dmul(a,a);
	}
	return ans;
}
int inv(int a){return ksm(a,mod-2);}

const int N=202;
int det(int a[N][N],int n){
	int ans=1;
	D(i,n){
		if(!a[i][i]){
			F(j,i+1,n-1)if(a[j][i]){
				ans=sub(0,ans);
				swap_ranges(a[i]+i,a[i]+n,a[j]+i);
				goto ok;
			}
			return 0;
			ok:;
		}
		int iv=inv(a[i][i]);
		F(j,i+1,n-1){
			int x=mul(a[j][i],iv);
			F(k,i+1,n-1)dsub(a[j][k],mul(a[i][k],x));
		}
	}
	D(i,n)dmul(ans,a[i][i]);
	return ans;
}

struct UFS{
	int fa[N*N];
	void init(){memset(fa,-1,sizeof(fa));}
	int find(int x){return fa[x]==-1?x:(fa[x]=find(fa[x]));}
	bool merge(int x,int y){
		x=find(x);
		y=find(y);
		if(x==y)return false;
		fa[x]=y;
		return true;
	}
}ufs;

int n,m;
char a[N][N];
int solve(int d){
	// cerr<<"solve "<<d<<endl;
	int stars=0;
	ufs.init();
	F(i,1,n)F(j,1,m){
		if(a[i][j]!='*'){
			bool col=(i^j^d)&1;
			bool tp=a[i][j]=='/';
			if(col==tp){
				int a1=(i-1)*(m+1)+j-1+tp;
				int a2=i*(m+1)+j-tp;
				// cerr<<a1<<" "<<a2<<endl;
				if(!ufs.merge(a1,a2))return 0;
			}
		}
		else{
			stars++;
		}
	}
	// cerr<<stars<<endl;
	V roots;
	F(i,0,n)F(j,0,m)if(((i^j)&1)==d){
		int id=i*(m+1)+j;
		if(ufs.find(id)==id){
			// cerr<<"root "<<id<<endl;
			roots.push_back(id);
		}
	}
	int rtCnt=roots.size();
	if(rtCnt>stars+1)return 0;
	map<int,int> rid;
	D(i,rtCnt)rid[roots[i]]=i;
	static int mat[N][N];
	memset(mat,0,sizeof(mat));
	F(i,1,n)F(j,1,m){
		if(a[i][j]=='*'){
			bool tp=(i^j^d)&1;
			int a1=ufs.find((i-1)*(m+1)+j-1+tp);
			int a2=ufs.find(i*(m+1)+j-tp);
			// cerr<<"et "<<a1<<" "<<a2<<endl;
			if(a1!=a2){
				int u=rid[a1],v=rid[a2];
				// cerr<<"e "<<u<<" "<<v<<endl;
				dadd(mat[u][u],1);
				dsub(mat[u][v],1);
				dadd(mat[v][v],1);
				dsub(mat[v][u],1);
			}
		}
	}
	return det(mat,rtCnt-1);
}

int main(){
	n=read();
	m=read();
	mod=read();
	F(i,1,n)scanf("%s",a[i]+1);
	int ans=add(solve(0),solve(1));
	printf("%d\n",ans);
	return 0;
}