#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

map<ll,vector<string>>m;
map<ll,vector<string>>m2;
vector<string>va;
vector<string>vb;

int main(){FIN;
	ll n; cin>>n;
	string s;
	string aeiou="aeiou";
	fore(i,0,n){
		cin>>s;
		ll tot=0,l=-1;
		for(int i=SZ(s)-1;i>=0;i--){
			fore(j,0,5){
				if(s[i]==aeiou[j]){
					tot++;
					if(l==-1)l=j;
				}
			}
		}
		m[5*tot+l].pb(s);
	}
	/*for(auto i:m){
		cout<<i.fst<<" : ";
		for(auto j:i.snd){
			cout<<j<<" ";
		}
		cout<<endl;
	}*/
	ll tota=0,totb=0;
	for(auto i:m){
		if(SZ(i.snd)%2==1){
			m2[i.fst/5].pb(i.snd.back());
			//i.snd.pop_back();
			//if(SZ(i.snd)==0)m.erase(i.fst);
			totb+=SZ(i.snd)/2;
			fore(j,0,SZ(i.snd)-1)vb.pb(i.snd[j]);
		}else{
			totb+=SZ(i.snd)/2;
			fore(j,0,SZ(i.snd))vb.pb(i.snd[j]);
		}
	}
	for(auto i:m2){
		tota+=SZ(i.snd)/2;
		fore(j,0,SZ(i.snd)-SZ(i.snd)%2)va.pb(i.snd[j]);
	}
	/*for(auto i:m2){
		cout<<i.fst<<" : ";
		for(auto j:i.snd){
			cout<<j<<" ";
		}
		cout<<"\n";
	}*/
	//cout<<tota<<" "<<totb<<endl;
	//fore(i,0,SZ(va))cout<<va[i]<<" "; cout<<endl;
	//fore(i,0,SZ(vb))cout<<vb[i]<<" "; cout<<endl;
	ll res=0;
	if(tota>totb)res=totb;
	else res=(tota+totb)/2;
	
/*	vector<string>res;
	for(auto i:m2){
		if(SZ(i.snd)>1){
			res.pb(i.snd.back()); res.pop_back();
			res.pb(i.snd.back()); res.pop_back();
		}
	}*/
	cout<<res<<"\n";
	fore(i,0,res){
		if(SZ(va)>=2){
			cout<<va.back()<<" "; va.pop_back();
			cout<<vb.back()<<"\n"; vb.pop_back();
			cout<<va.back()<<" "; va.pop_back();
			cout<<vb.back()<<"\n"; vb.pop_back();
		}else{
			cout<<vb.back()<<" "; vb.pop_back();
			cout<<vb[SZ(vb)-2]<<"\n";
			cout<<vb.back()<<" "; vb.pop_back(); vb.pop_back();
			cout<<vb.back()<<"\n"; vb.pop_back();
		}
	}
	
	return 0;
}