#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		sort(ALL(s));
		map<char,ll> m;
		fore(i,0,SZ(s)){
			if(m.count(s[i])){
				m[s[i]]++;
			}else{
				m[s[i]]=1;
			}
		}
		vector<char> v;
		for(auto i:m){
			v.pb(i.fst);
		}
		if(SZ(m)==1){
			cout<<s<<"\n"; continue;
		}
		if(SZ(m)==2){
			if(abs(v[0]-v[1])<=1){
				cout<<"No answer\n"; continue;
			}
			fore(i,0,m[v[0]]){
				cout<<v[0];
			}
			fore(i,0,m[v[1]]){
				cout<<v[1];
			}
			cout<<"\n"; continue;
		}
		if(SZ(m)==3){
			if(abs(v[0]-v[1])<=1&&abs(v[1]-v[2])<=1){
				cout<<"No answer\n"; continue;
			}
			if(abs(v[0]-v[1])>1){
				fore(i,0,m[v[1]]){
					cout<<v[1];
				}
				fore(i,0,m[v[0]]){
					cout<<v[0];
				}
				fore(i,0,m[v[2]]){
					cout<<v[2];
				}
				cout<<"\n"; continue;
			}
			fore(i,0,m[v[1]]){
				cout<<v[1];
			}
			fore(i,0,m[v[2]]){
				cout<<v[2];
			}
			fore(i,0,m[v[0]]){
				cout<<v[0];
			}
			cout<<"\n"; continue;
		}
		vector<char> ve[2];
		fore(i,0,SZ(v)){
			ve[i%2].pb(v[i]);
		}
		reverse(ALL(ve[0]));
		reverse(ALL(ve[1]));
		fore(k,0,2){
			for(auto i:ve[k]){
				fore(j,0,m[i])cout<<i;
			}
		}
		cout<<"\n"; continue;
	}
	
	return 0;
}