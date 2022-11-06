#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll cont=0,n;

ll ask(ll a,ll b,ll c,ll d){
	cont++;
	assert(cont<=n*n);
	cout<<"? "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	ll resp; cin>>resp;
	assert(resp!=-1);
	return resp;
}

int main(){FIN;
	cin>>n;
	ll res[n][n];
	mset(res,0);
	res[0][0]=1;
	fore(i,0,n){
		fore(j,0,n){
			if((i+j)%2==0){
				if(i==n-1&&j==n-1)continue;
				if(i==0&&j!=0){
					res[i][j]=(res[i][j-2]+ask(i+1,j-1,i+1,j+1)+1)%2;
				}else if(j==0&&i!=0){
					res[i][j]=(res[i-2][j]+ask(i-1,j+1,i+1,j+1)+1)%2;
				}else if(i!=0&&j!=0){
					res[i][j]=(res[i-1][j-1]+ask(i,j,i+1,j+1)+1)%2;
				}
			}
		}
	}
	fore(i,0,n/2-1){
		res[2*i+3][0]=(res[2*i+1][0]+ask(2*i+2,1,2*i+4,1)+1)%2;
	}
	res[2][1]=(res[1][0]+ask(2,1,3,2)+1)%2;
	res[0][1]=(res[2][1]+ask(1,2,3,2)+1)%2;
	fore(i,0,n){
		fore(j,1,n){
			if((i+j)%2!=0){
				if((i==2&&j==1)||(i==0&&j==1))continue;
				if(j==1){
					res[i][1]=(res[i-1][0]+ask(i,1,i+1,2)+1)%2;
				}else{
					res[i][j]=(res[i][j-2]+ask(i+1,j-1,i+1,j+1)+1)%2;
				}
			}
		}
	}
	fore(i,0,2*n-4){
		if((res[min(i,n-1)][max(0ll,i-n+1)]+res[min(i+2,n-1)][max(0ll,i+2-n+1)])%2==(res[min(i+1,n-1)][max(0ll,i+1-n+1)]+res[min(i+3,n-1)][max(0ll,i+3-n+1)])%2){
			ll es=((res[min(i,n-1)][max(0ll,i-n+1)]==res[min(i+3,n-1)][max(0ll,i+3-n+1)])&&(res[min(i+1,n-1)][max(0ll,i+1-n+1)]==res[min(i+2,n-1)][max(0ll,i+2-n+1)]));
			if((es+ask(min(i,n-1)+1,max(0ll,i-n+1)+1,min(i+3,n-1)+1,max(0ll,i+3-n+1)+1))%2){
				fore(ii,0,n){
					fore(jj,0,n){
						if((ii+jj)%2)res[ii][jj]++,res[ii][jj]%=2;
					}
				}
				break;
			}else break;
		}
	}
	cout<<"!"<<endl;
	fore(i,0,n){
		fore(j,0,n){
			cout<<res[i][j];
		}
		cout<<endl;
	}
	return 0;
}