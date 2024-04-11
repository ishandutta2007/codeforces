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

int main(){FIN;
	ll n; cin>>n;
	string s; cin>>s;
	ll a=0,b=0;
	fore(i,0,SZ(s)){
		if(s[i]=='0')a++;
		else b++;
	}
	if(a==b){
		cout<<"2\n"<<s[0]<<" ";
		fore(i,1,SZ(s))cout<<s[i];
		
	}else{
		cout<<1<<"\n"<<s;
	}
	
	return 0;
}