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
	ll a,b; cin>>a>>b;
	if(a==b){
		cout<<a<<"0 "<<b<<"1 "; return 0;
	}else if(a+1==b){
		cout<<a<<" "<<b; return 0;
	}else if(a==9&&b==1){
		cout<<"9 10"; return 0;
	}else{
		cout<<-1;
	}
	
	return 0;
}