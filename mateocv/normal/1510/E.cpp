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

pair<pair<ll,ll>,pair<ll,ll>> calc(ll mk, ll len){
	pair<pair<ll,ll>,pair<ll,ll>> res={{0,0},{0,0}};
	ll pos=0;
	fore(i,0,len){
		if((1ll<<i)&mk){
			res.fst.snd+=2*pos+1;
			res.snd.fst+=(3*pos+1)*i+(3*pos+2)*(i+1);
			res.snd.snd+=3*pos*pos+3*pos+1;
			pos++;
		}else{
			res.fst.snd+=2*pos-1;
			res.snd.fst+=(3*pos-1)*i+(3*pos-2)*(i+1);
			res.snd.snd+=3*pos*pos-3*pos+1;
			pos--;
		}
	}
	res.fst.fst=pos;
	return res;
}

set<pair<ll,ll>> st[20][700];

ld EPS=1e-4;

ll neint(ld x){
	ll a=ll(x);
	if(abs(a-x)<EPS)return a;
	if(abs(a+1-x)<EPS)return a+1;
	return -1;
}

ll n;

ll val(ll mk){
	ll va=0;
	fore(j,0,(n/2)){
		if((1ll<<j)&mk)va++;
		else va--;
		if(va<0)return 0;
	}
	return 1;
}

ll inv(pair<pair<ll,ll>,pair<ll,ll>> r){
	fore(i,0,(1ll<<(n/2))){
		if(val(i)&&calc(i,n/2)==r){
			return i;
		}
	}
	//assert(0);
	return -1;
}

void print(pair<pair<ll,ll>,pair<ll,ll>> r){
	cout<<r.fst.fst<<" "<<r.fst.snd<<" "<<r.snd.fst<<" "<<r.snd.snd<<"\n";
}

int main(){FIN;
	cin>>n;
	ld x,y; cin>>x>>y;
	x*=3.; y*=3.;
	fore(i,0,(1ll<<(n/2))){
		if(val(i)){
			auto c=calc(i,n/2);
			//cout<<bitset<3>(i)<<" -> ";
			//print(c);
			st[c.fst.fst][c.fst.snd].insert(c.snd);
		}
	}
	pair<pair<ll,ll>,pair<ll,ll>> resx={{-1,-1},{-1,-1}},resy={{-1,-1},{-1,-1}};
	fore(i,1,650){
		ll xx=neint(x*i),yy=neint(y*i);
		if(xx!=-1&&yy!=-1){
			fore(ii,0,i+1){
				fore(jj,0,19){
					for(auto pi:st[jj][ii]){
						if(st[jj][i-ii].count({(i-ii)*3*n-xx+pi.fst,yy-pi.snd})){
							resx={{jj,ii},pi};
							resy={{jj,i-ii},{(i-ii)*3*n-xx+pi.fst,yy-pi.snd}};
						}
					}
				}
			}
		}
	}
	//assert(resx.fst.fst!=-1);
	ll mkx=inv(resx);
	ll mky=inv(resy);
	fore(i,0,(n/2)){
		if((1ll<<i)&mkx)cout<<'(';
		else cout<<')';
	}
	string s;
	fore(i,0,(n/2)){
		if((1ll<<i)&mky)s+='(';
		else s+=')';
	}
	reverse(ALL(s));
	fore(i,0,SZ(s))s[i]^='('^')';
	cout<<s<<"\n";
	
	return 0;
}