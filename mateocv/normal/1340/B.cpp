#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll n,k;
string s[2020];

vector<string> d={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

ll dp[2020][2020];

ll f(ll x, ll y){
	ll &r=dp[x][y];
	if(r>=0)return r;
	if(x==n){
		if(y!=0)return r=10;
		else return r=0;
	}
	r=-1;
	fore(i,0,10){
		ll tot=0,br=0;
		fore(j,0,7){
			if(s[x][j]=='1'&&d[i][j]=='0'){
				br++; break;
			}
			if(s[x][j]=='0'&&d[i][j]=='1')tot++;
		}
		if(br)continue;
		if(y-tot<0)continue;
		if(f(x+1,y-tot)!=10){
			r=max(r,i);
		}
	}
	//cout<<x<<" "<<y<<" "<<r<<endl;
	if(r==-1)return r=10;
	else return r;
}

int main(){FIN;
	cin>>n>>k;
	fore(i,0,n)cin>>s[i];
	mset(dp,-1);
	string res;
	ll va=k;
	fore(i,0,n){
		if(f(i,va)==10){
			cout<<-1; return 0;
		}
		res+=(char)(f(i,va)+'0');
		ll tot=0;
		ll nn=f(i,va);
		fore(j,0,7){
			if(s[i][j]=='0'&&d[nn][j]=='1')tot++;
		}
		va-=tot;
	}
	cout<<res;
	return 0;
}