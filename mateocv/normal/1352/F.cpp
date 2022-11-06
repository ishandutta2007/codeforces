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

ll dp[105][105][105][2];

ll f(ll x, ll y, ll z, ll b){
	ll &r=dp[x][y][z][b];
	if(r>=0)return r;
	if(x==0&&y==0&&z==0){
		return r=1;
	}
	if(b==0){
		r=0;
		if(x>0)r=r||f(x-1,y,z,0);
		if(y>0)r=r||f(x,y-1,z,1);
	}
	if(b==1){
		r=0;
		if(z>0)r=r||f(x,y,z-1,1);
		if(y>0)r=r||f(x,y-1,z,0);
	}
	//cout<<x<<" "<<y<<" "<<z<<" "<<r<<endl;
	return r;
}

int main(){FIN;
	mset(dp,-1);
	ll t; cin>>t;
	while(t--){
		ll a,b,c; cin>>a>>b>>c;
		string res;
		ll d=-1;
		if(f(a,b,c,0)){
			res+='0';
			d=0;	
		}else{
			res+='1';
			d=1;
		}
		fore(i,0,a+b+c){
			fore(j,0,2){
				if(d+j==0&&a>0&&f(a-1,b,c,j)){
					res+=j+'0';
					a--;
					d=j;
					break;
				}
				if(d+j==1&&b>0&&f(a,b-1,c,j)){
					res+=j+'0';
					b--;
					d=j;
					break;
				}
				if(d+j==2&&c>0&&f(a,b,c-1,j)){
					res+=j+'0';
					c--;
					d=j;
					break;
				}
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}