#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
const int N=3636;
const int MOD=998244353;
int add(int a,int b){
	return (a+b)>=MOD?a+b-MOD:a+b;
}
void dadd(int &a,int b){
	a=add(a,b);
}
int mul(int a,int b){
	return (LL)a*b%MOD;
}
int sqr(int a){return mul(a,a);}
int ksm(int a,int b){
	return b==0?1:mul(sqr(ksm(a,b>>1)),b&1?a:1);
}
int inv(int a){
	return ksm(a,MOD-2);
}
int frac[N];
int ifr[N];

bool qx[N]={false};
bool qy[N]={false};
int c(int n,int k){
	return k<0||k>n?0:mul(frac[n],mul(ifr[k],ifr[n-k]));
}

int gx[N];
int gy[N];

int nxt[N];
int f[N][N];
void solve(int n,bool q[N],int ans[N]){
	q[n+1]=true;
	nxt[n+1]=n+1;
	for(int i=n;i>=1;i--){
		nxt[i]=q[i]?nxt[i+1]:i;
	}
	memset(f,0,sizeof(f));
	f[nxt[1]][0]=1;
	for(int i=1;i<=n;i++)if(!q[i]){
		for(int j=0;j<=n;j++){
			int a=f[i][j];
			//pass
			dadd(f[nxt[i+1]][j],a);
			//go
			if(!q[i+1]){
				dadd(f[nxt[i+2]][j+1],a);
			}
		}
	}
	F(i,0,n)ans[i]=f[n+1][i];
}

int main(){
	frac[0]=ifr[0]=1;
	F(i,1,N-1){
		frac[i]=mul(frac[i-1],i);
		ifr[i]=inv(frac[i]);
	}
	ios::sync_with_stdio(false);
	int h,w,n;
	cin>>h>>w>>n;
	while(n--){
		F(i,1,2){
			int x,y;
			cin>>x>>y;
			qx[x]=true;
			qy[y]=true;
		}
	}
	solve(h,qx,gx);
	solve(w,qy,gy);
	// for(int i=0;i<=h;i++){
	// 	cerr<<gx[i]<<" ";
	// }
	// cerr<<endl;
	// for(int i=0;i<=w;i++){
	// 	cerr<<gy[i]<<" ";
	// }
	// cerr<<endl;
	int ans=0;
	int rh=h,rw=w;
	F(i,1,h)rh-=qx[i];
	F(i,1,w)rw-=qy[i];
	// cerr<<rh<<" "<<rw<<endl;
	// cerr<<c(5,3)<<endl;
	F(i,0,h)F(j,0,w){
		dadd(ans,mul(mul(frac[i],frac[j]),mul(mul(gx[i],gy[j]),mul(c(rw-j*2,i),c(rh-i*2,j)))));
	}
	cout<<ans<<endl;
	return 0;
}