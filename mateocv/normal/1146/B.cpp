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

string sina(string s){
	
	
}

int main(){FIN;
	string t; cin>>t;
	vector<char> v;
	fore(i,0,SZ(t)){
		if(t[i]!='a')v.pb(t[i]);
	}
	if(SZ(v)%2){
		cout<<":("; return 0;
	}
	fore(i,0,SZ(v)/2){
		if(v[i]!=v[i+SZ(v)/2]){
			cout<<":("; return 0;
		}
	}
	string s;
	fore(i,0,SZ(t)-SZ(v)/2){
		s+=t[i];
	}
	string res=s;
	fore(i,0,SZ(s)){
		if(s[i]!='a'){
			res+=s[i];
		}
	}
	if(res==t){
		cout<<s;
	}else{
		cout<<":("; return 0;
	}
	
	return 0;
}