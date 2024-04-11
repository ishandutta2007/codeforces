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

string s; vector<char> v;
void red(char c){
	ll va=0;
	fore(i,0,SZ(s)){
		if(va==0){
			if(s[i]==c){
				va++; v.pb(c);
			}
		}else if(va==1){
			if(s[i]==':'){
				va++; v.pb(':');
			}
		}else{
			if(s[i]=='|'||s[i]==':'||(s[i]=='['&&c!='[')||(s[i]==']'&&c!=']')){
				v.pb(s[i]);
			}
		}
	}
	s="";
}

int main(){FIN;
	cin>>s;
	red('[');
	
	/*fore(i,0,SZ(v)){
		cout<<v[i]<<" ";
	}
	cout<<"\n";*/
	
	fore(i,1,SZ(v)+1){
		s+=v[SZ(v)-i];
	}
//	cout<<s<<"\n";
	v.clear();
	red(']');
	
	/*fore(i,0,SZ(v)){
		cout<<v[i]<<" ";
	}
	cout<<"\n";*/
	
	ll res=0,val=0;
	reverse(ALL(v));
	
/*	fore(i,0,SZ(v)){
		cout<<v[i]<<" ";
	}
	cout<<"\n";*/
	
	fore(i,0,SZ(v)){
		if((i==0&&v[i]=='[')||(i==SZ(v)-1&&v[i]==']')||(i==1&&v[i]==':')||(i==SZ(v)-2&&i>1&&v[i]==':')){////// caso [:]
			val++; res++;
		}else{
			if(v[i]=='|'&&i>1&&i<SZ(v)-2)res++;
		}
	}
	//cout<<val<<" ";
	if(val==4){
		cout<<res;
	}else{
		cout<<-1;
	}
	
	return 0;
}