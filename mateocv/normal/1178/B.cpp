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

ll contar(string s, char c){
	ll res=0;
	fore(i,0,SZ(s)){
		res+=(s[i]==c);
	}
	return res;
}

int main(){FIN;
	string s; cin>>s;
	ll O=contar(s,'o');
	ll V=contar(s,'v');
	//char va='.'; 
	ll van=0;
	s+='o';
	vector<ll> v;
	fore(i,0,SZ(s)){
		if(s[i]=='v')van++;
		else{
			v.pb(max(van-1,0ll));
			van=0;
		}
	}
	//fore(i,0,SZ(v))cout<<v[i]<<" ";
	ll sum=0;
	fore(i,0,SZ(v))sum+=v[i];
	ll sump=0;
	ll res=0;
	fore(i,0,SZ(v)){
		sump+=v[i]; sum-=v[i];
		res+=sump*sum;
	}
	/*ll res=0;
	fore(i,0,SZ(s)){
		if(s[i]=='o'){
			res+=((va*(va-1))/2)*(((V-va)*(V-va-1))/2);
		}else{
			va++;
		}
	}*/
	cout<<res;
	return 0;
}