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

ll subs(string a, string b){
	ll pos=0;
	fore(i,0,SZ(b)){
		if(a[pos]==b[i])pos++;
		if(pos==SZ(a))break;
	}
	return pos;
}

pair<ll,ll> cont(string s){
	pair<ll,ll> res={0,0};
	for(auto i:s){
		res.fst+=(i=='0');
		res.snd+=(i=='1');
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string a,b,c; cin>>a>>b>>c;
		auto pa=cont(a);
		auto pb=cont(b);
		auto pc=cont(c);
		ll tot[2]={0,0};
		tot[pa.snd>=n]++;
		tot[pb.snd>=n]++;
		tot[pc.snd>=n]++;
		string res;
		if(tot[0]>=2){
			vector<string> v;
			if(pa.fst>=n)v.pb(a);
			if(pb.fst>=n)v.pb(b);
			if(pc.fst>=n)v.pb(c);
			assert(SZ(v)>=2);
			if(SZ(v)==3)v.pop_back();
			ll l=0,r=0;
			while(l<SZ(v[0])&&r<SZ(v[1])){
				if(v[0][l]=='0'&&v[1][r]=='0'){
					res+='0';
					l++; r++;
				}else if(v[0][l]=='1'){
					res+='1';
					l++;
				}else if(v[1][r]=='1'){
					res+='1';
					r++;
				}
			}
			while(l<SZ(v[0])){
				res+=v[0][l];
				l++;
			}
			while(r<SZ(v[1])){
				res+=v[1][r];
				r++;
			}
		}else{
			vector<string> v;
			if(pa.snd>=n)v.pb(a);
			if(pb.snd>=n)v.pb(b);
			if(pc.snd>=n)v.pb(c);
			assert(SZ(v)>=2);
			if(SZ(v)==3)v.pop_back();
			ll l=0,r=0;
			while(l<SZ(v[0])&&r<SZ(v[1])){
				if(v[0][l]=='1'&&v[1][r]=='1'){
					res+='1';
					l++; r++;
				}else if(v[0][l]=='0'){
					res+='0';
					l++;
				}else if(v[1][r]=='0'){
					res+='0';
					r++;
				}
			}
			while(l<SZ(v[0])){
				res+=v[0][l];
				l++;
			}
			while(r<SZ(v[1])){
				res+=v[1][r];
				r++;
			}
		}
		cout<<res<<"\n";
		assert(SZ(res)<=3*n);
	}
	
	return 0;
}