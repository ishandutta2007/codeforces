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

ll n;

string al;
map<char,ll> ual;
ll ub[11][60][2];

ll dp[(1ll<<11)][60];

ll find_ne(ll x, ll y, ll z){
	ll res=0;
	fore(i,0,n){
		ll pos=ub[i][y][!!((1ll<<i)&x)];
		if(max(ub[i][z][0],ub[i][z][1])<=pos)return -1;
		if(ub[i][z][0]<=pos)res+=(1ll<<i);
	}
	return res;
}

ll f(ll x, ll y){
	ll &res=dp[x][y];
	if(res>=0)return res;
	res=0;
	fore(i,0,SZ(al)){
		auto ne=find_ne(x,y,i);
		if(ne!=-1)res=max(res,f(ne,i));
	}
	res++;
	return res;
}

int main(){FIN;
	fore(i,0,26)al+='a'+i;
	fore(i,0,26)al+='A'+i;
	fore(i,0,SZ(al))ual[al[i]]=i;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		vector<string> s(n);
		fore(i,0,n)cin>>s[i];
		mset(ub,-1);
		fore(i,0,n){
			fore(j,0,SZ(s[i])){
				if(ub[i][ual[s[i][j]]][0]==-1)ub[i][ual[s[i][j]]][0]=j;
				else ub[i][ual[s[i][j]]][1]=j;
			}
		}
		mset(dp,-1);
		ll resp=0;
		ll cant[60];
		mset(cant,0);
		fore(i,0,n){
			fore(j,0,SZ(al)){
				cant[j]+=(ub[i][j][0]!=-1);
			}
		}
		fore(i,0,SZ(al)){
			if(cant[i]==n)resp=max(resp,f(0,i));
		}
		cout<<resp<<"\n";
		string res;
		ll x=0,y=0;
		fore(i,0,SZ(al)){
			if(cant[i]==n&&f(0,i)==resp){
				res+=al[i];
				resp--;
				y=i;
				break;
			}
		}
		while(resp){
			fore(i,0,SZ(al)){
				auto ne=find_ne(x,y,i);
				if(ne!=-1&&f(ne,i)==resp){
					res+=al[i];
					resp--;
					x=ne;
					y=i;
					break;
				}
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}