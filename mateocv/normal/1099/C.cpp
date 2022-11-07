#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

string s;

ll contar(char c){
	ll res=0;
	fore(i,0,SZ(s)){
		if(s[i]==c)res++;
	}
	return res;
}

int main(){FIN;
	ll k; cin>>s>>k;
	ll n=SZ(s);
	n-=contar('?')+contar('*');
	vector<char> res;
	if(k<=n){
		if(k>=n-(contar('?')+contar('*'))){
			ll dif=n-k;
			fore(i,0,SZ(s)){
				if(s[i]!='?'&&s[i]!='*'){
					res.pb(s[i]);
				}else{
					if(dif>0){
						res.pop_back(); dif--;
					}
				}
			}
		}else{
			cout<<"Impossible"; return 0;
		}	
	}else{
		if(contar('*')){
			ll lis=0,dif=k-n;
			fore(i,0,SZ(s)){
				if(s[i]!='?'&&s[i]!='*'){
					res.pb(s[i]);
				}else{
					if(s[i]=='*'&&!lis){
						while(dif--){
							res.pb(s[i-1]);
						}
						lis++;
					}
					
				}
			}
		}else{
			cout<<"Impossible"; return 0;
		}
	}
	
	fore(i,0,SZ(res)){
		cout<<res[i];
	}
	
	return 0;
}