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
	ll q; cin>>q;
	pair<ll,ll> a[q];
	fore(i,0,q)cin>>a[i].fst,a[i].snd=i;
	sort(a,a+q);
	ll l=0;
	string s;
	ll va=0;
	char res[q];
	fore(i,1,100001){
		s+=to_string(i);
		//cout<<s<<"\n";
		while(a[l].fst<=va+SZ(s)){
		    //cout<<s[a[l].fst-va-1]<<"\n";
		    res[a[l].snd]=s[a[l].fst-va-1];
		    l++;
		    if(l==q){
		        fore(i,0,q)cout<<res[i]<<"\n";
		        return 0;
		    }
		}
		va+=SZ(s);
	}
	
	return 0;
}