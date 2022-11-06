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

int main(){FIN;
	ll n; cin>>n;
	string s; cin>>s;
	ll res=0;
	fore(i,0,SZ(s)/2){
		if(s[2*i]==s[2*i+1]){
			res++;
			if(s[2*i]=='a'){
				s[2*i]='b';
			}else{
				s[2*i]='a';
			}
		}
	}
	cout<<res<<"\n";
	cout<<s;
	return 0;
}