#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll igual(string &s){
	fore(i,0,SZ(s)){
		if(s[0]!=s[i])return 0;
	}
	return 1;
}

ll espal(string &s){
	string s1=s;
	reverse(s1.begin(),s1.end());
	if(s==s1)return 1;
	return 0;
}

int main(){FIN;
	string s; cin>>s;
	if(igual(s)){
		cout<<"Impossible";
	}else if(SZ(s)%2==1){
	s[(SZ(s))/2]=s[0];
	if(igual(s)){cout<<"Impossible";
	}else{cout<<2;
	}
	}else{ll ok=0;
		string st=s;
		fore(i,0,SZ(s)-1){
			string s1;
			fore(j,1,SZ(s)){
				s1+=s[j];
			}
			s1+=s[0];
			if(espal(s1)&&(s1!=st)){ok++;/* cout<<s1; */break;
			}
			s=s1;
		}
		if(ok){cout<<1;
		}else{cout<<2;
		}
	
	
	/*	string s1,s2;
		fore(i,0,SZ(s)/2){
			s1+=s[i];
			s2+=s[SZ(s)/2+i];
		}
		if(s1==s2){ll ok=0;
		fore(i,0,SZ(s)/2){
			s1=""; s2="";
			fore(j,0,i){
				s1+=s[j];
				s2+=s[i+j];
			}
			reverse(s2.begin(),s2.end());
			if(s1==s2){
			cout<<1;ok++; break;}
		}if(!ok){
		cout<<2;}
		}else{cout<<1;
		}*/
		//cout<<s1<<" "<<s2;
	}
	
	
	return 0;
}