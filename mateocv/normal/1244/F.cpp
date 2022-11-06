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

string con(ll n, ll k, ll a){
	string s;
	char ca='B'+a*('W'-'B');
	char cca='B'+(ca=='B')*('W'-'B');
	if(n==0)return "";
	if(k==0){
		fore(i,0,n){
			if(i%2==0)s+=cca;
			else s+=ca;
		}
		return s;
	}
	if(n==1){
		s=ca; return s;
	}
	ll kk=min(k,(n+1)/2);
	fore(i,0,kk){
		s+=ca;
	}
	//s+=ca;
	s+=con(max(n-2*kk,0ll),0,a);
	fore(i,0,kk){
		if(n%2){
			if(i!=kk-1||2*kk<=n)s+=ca;
		}else{
			s+=cca;
		}
	}
	return s;
}

ll dist(string &s){
	fore(i,0,SZ(s)){
		if(s[i]==s[(i+1)%SZ(s)])return 0;
	}
	return 1;
}

int main(){FIN;
	ll n,k; cin>>n>>k;
	string s; cin>>s;
	//ll a; cin>>a;
	//cout<<con(n,k,a);
	//return 0;
	if(dist(s)){
		if(k&1){
			fore(i,0,n)cout<<s[(i+1)%SZ(s)]; return 0;
		}else{
			cout<<s; return 0;
		}
	}
	string res=s;
	fore(i,0,n){
		if(s[i]!=s[(i-1+n)%n]&&s[i]!=s[(i+1)%n]){
			res[i]='.';
		}else{
			res[i]=s[i];
		}
	}
	vector<pair<ll,ll>> v;
	fore(i,0,n){
		if(res[i]=='.'&&res[(i-1+n)%n]!='.'){
			v.pb({1,i});
		}
		if(res[i]=='.'&&res[(i+1)%n]!='.'){
			v.pb({-1,i});
		}
	}
	//for(auto i:v)cout<<i.fst<<" "<<i.snd<<"\n";
	fore(i,0,SZ(v)){
		if(v[i].fst==1){
			string t=con(v[(i+1)%SZ(v)].snd+n*(i+1==SZ(v))-v[i].snd+1,k,s[(v[i].snd-1+n)%n]=='W');
			//cout<<t<<"\n";
			fore(j,0,SZ(t)){
				res[(v[i].snd+j)%n]=t[j];
			}
		}
	}
	cout<<res;
	
	return 0;
}