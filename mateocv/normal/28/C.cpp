#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;

ll n,m;
ll a[55];
ld dp[55][55][55][2];

ld comb(ll n, ll k){
	ld res=1;
	fore(i,0,k){
		res*=1.*(n-i)/(i+1);
	}
	return res;
}

ld f(ll x, ll y, ll z, ll b){
	ld &r=dp[x][y][z][b];
	if(r>=0)return r;
	if(x==m){
		if(b||y>0){
			r=0; return r;
		}
		r=1; return r;
	}
	r=0;
	fore(i,0,min(z*a[x],y)+1){
		if((i+a[x]-1)/a[x]==z){
			r+=f(x+1,y-i,z,0)*pow(m-x-1,y-i)*comb(y,i)/pow(m-x,y); /*pow(m-1,n-i)*comb(n,i)/pow(m,n)*/
		}else{
			r+=f(x+1,y-i,z,b)*pow(m-x-1,y-i)*comb(y,i)/pow(m-x,y); /*pow(m-1,n-i)*comb(n,i)/pow(m,n)*/
		}
	}
	//cout<<x<<" "<<y<<" "<<z<<" "<<b<<" -> "<<r<<"\n";
	return r;
}

int main(){FIN;
	cin>>n>>m;	
	fore(i,0,m)cin>>a[i];
	fore(i,0,55)fore(j,0,55)fore(k,0,55)fore(kk,0,2)dp[i][j][k][kk]=-1;
	/*fore(i,0,10){
		fore(j,0,i+1){
			cout<<comb(i,j)<<" ";
		}
		cout<<"\n";
	}*/
	ld res=0;
	fore(i,1,n+1)res+=f(0,n,i,1)*i;
	cout<<fixed<<setprecision(20)<<res;
	return 0;
}