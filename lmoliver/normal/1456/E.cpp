#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define D(N,E) for(int N=0;N<(int)(E);N++)
typedef vector<int> V;

template<class T=LL>
T read(){
	T x=0;
	char ch=0;
	bool f=false;
	while(!isdigit(ch))f|=(ch=getchar())=='-';
	for(;isdigit(ch);ch=getchar())x=x*10+(ch^'0');
	return f?-x:x;
}

int n,k;
const int N=55;
LL l[N],r[N];
LL c[N];
LL dp[N][N*4][N*4];

LL v(int s,int d){
	int x=s>>2;
	LL v=(1LL<<k)-(1LL<<d);
	LL f=(s&1?l:r)[x]&v;
	if(!(s&2)){
		return f;
	}
	else{
		LL w=f^(1LL<<d);
		if(w>=l[x]&&(w|((1LL<<d)-1))<=r[x]){
			return w;
		}
		else if(f>=l[x]&&(f|((1LL<<d)-1))<=r[x]){
			return f;
		}
		else return -1;
	}
}
int main(){
	n=read();
	k=read();
	F(i,1,n){
		l[i]=read();
		r[i]=read();
	}
	D(i,k)c[i]=read();
	// D(d,k){
	// 	F(i,1,n)D(s,4){
	// 		cerr<<"d="<<d<<" v("<<i<<"#"<<s<<")="<<v(i*4+s,d)<<endl;
	// 	}
	// }
	for(int d=k-1;d>=0;d--){
		F(len,1,n+1){
			F(l,0,n+1-len){
				int r=l+len;
				D(ls,4)D(rs,4){
					int sl=(l*4)|ls;
					int sr=(r*4)|rs;
					LL &ans=dp[d][sl][sr];
					// int op=-1;
					ans=1e18;
					if(d+1<k||l+1==r){
						ans=dp[d+1][sl&~2][sr&~2]+c[d]*((l>=1&&r<=n)&&((v(sl,d)^v(sr,d))&(1LL<<d)));
						// op=0;
					}
					F(x,l+1,r-1){
						D(xs,2){
							int sx=(x*4)|2|xs;
							if(v(sx,d)!=-1){
								LL tans=dp[d][sl][sx]+dp[d][sx][sr];
								if(tans<ans){
									ans=tans;
									// op=x*100+xs;
								}							
							}
						}
					}
					// cerr<<d<<" "<<l<<" "<<ls<<" "<<r<<" "<<rs<<" "<<ans<<" "<<op<<endl;
				}
			}
		}
	}
	printf("%lld\n",dp[0][0][(n+1)*4]);
	return 0;
}