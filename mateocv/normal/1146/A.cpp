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

ll contar(string &s){
	ll res=0;
	fore(i,0,SZ(s)){
		res+=(s[i]=='a');
	}
	return res;
}

int main(){FIN;
	string s; cin>>s;
	if(contar(s)*2>SZ(s)){
		cout<<SZ(s);
	}else{
		cout<<2*contar(s)-1;
	}
	
	return 0;
}