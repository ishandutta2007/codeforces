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

ll is[10]={1,1,1,0,0,1,0,0,1,0};

ll trans(ll x){
	ll a=x/10,b=x%10;
	if(!is[a]||!is[b])return -1;
	if(a==2||a==5)a^=2^5;
	if(b==2||b==5)b^=2^5;
	return 10*b+a;
}

bool correct(ll a, ll b, ll h, ll m){
	ll aa=trans(a);
	ll bb=trans(b);
	return aa!=-1&&bb!=-1&&max(a,bb)<=h-1&&max(b,aa)<=m-1; 
}

string dosd(ll x){
	string res=to_string(x);
	while(SZ(res)<2)res='0'+res;
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll h,m; cin>>h>>m;
		string s; cin>>s;
		ll st=(10*(s[0]-'0')+(s[1]-'0'))*m+(10*(s[3]-'0')+(s[4]-'0'));
		ll br=0;
		fore(i,st,h*m){
			if(correct(i/m,i%m,h,m)){
				cout<<dosd(i/m)<<":"<<dosd(i%m)<<"\n";
				br++; break;
			}
		}
		if(br)continue;
		fore(i,0,st){
			if(correct(i/m,i%m,h,m)){
				cout<<dosd(i/m)<<":"<<dosd(i%m)<<"\n";
				br++; break;
			}
		}
	}
	
	return 0;
}