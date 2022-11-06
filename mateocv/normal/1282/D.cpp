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

ll ask(string s){
	cout<<s<<endl;
	ll resp; cin>>resp;
	assert(resp!=-1);
	if(resp==0)exit(0);
	return resp;
}

int main(){FIN;
	ll n=ask("a")+1;
	if(n==301){
		string t;
		fore(i,0,300)t.pb('b');
		ask(t);
	}
	string s;
	fore(i,0,n)s.pb('a');
	ll b=ask(s);
	if(b==n){
		string t;
		fore(i,0,n-1)t.pb('b');
		ask(t);
	}
	ll a=n-b;
	string res;
	ll vana=0;
	ll vanb=0;
	fore(i,0,n){
		string t=res;
		if(vanb<b)t.pb('b');
		fore(i,0,a-vana)t.pb('a');
		if(ask(t)==b-vanb-1){
			res.pb('b'); vanb++;
		}else{
			res.pb('a'); vana++;
		}
	}
	return 0;
}