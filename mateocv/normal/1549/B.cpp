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
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string sa,sb; cin>>sa>>sb;
		ll res=0;
		fore(i,0,n){
			if(sb[i]=='1'&&sa[i]=='0'){
				res++;
				sb[i]='0';
			}
		}
		fore(i,0,n){
			if(sb[i]!='1')continue;
			if(i-1>=0&&sa[i-1]=='1'){
				res++;
				sa[i-1]='0';
				sb[i]='0';
			}else if(i+1<n&&sa[i+1]=='1'){
				res++;
				sa[i+1]='0';
				sb[i]='0';
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}