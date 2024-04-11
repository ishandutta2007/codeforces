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

ll contar(string &s, char c){
	ll res=0;
	fore(i,0,SZ(s)){
		res+=(s[i]==c);
	}
	return res;
}

void fin(){
	cout<<":( "; exit(0);
}

ll check(string &s){
	ll cue=0;
	fore(i,0,SZ(s)){
		if(s[i]=='('){cue++;
		}else{
			cue--;
		}
		if(cue<0)return 0;
	}
	return 1;
}

int main(){FIN;
	ll n; cin>>n;
	string s; cin>>s;
	if(n%2||s[0]==')'||s[n-1]=='(')fin();
	if(n==2){
		cout<<"()"; return 0;
	}
	string t;
	fore(i,1,n-1){
		t+=s[i];
	}
	ll ab=(n-2)/2-contar(t,'(');
	ll ce=(n-2)/2-contar(t,')');
	//cout<<ab<<" "<<ce<<"\n";
	if(ab<0||ce<0)fin();
	ll va=0;
	while(ab){
		if(t[va]=='?'){
			t[va]='(';
			ab--;
		}
		va++;
	}
	while(ce){
		if(t[va]=='?'){
			t[va]=')';
			ce--;
		}
		va++;
	}
	if(check(t)){
		cout<<"("<<t<<")";
	}else{
		fin();
	}
	
	return 0;
}