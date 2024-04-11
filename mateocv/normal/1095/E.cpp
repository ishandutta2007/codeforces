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

ll contar(string &s, char c, ll pos){
	ll res=0;
	fore(i,0,pos){
		if(s[i]==c)res++;
	}
	return res;
}

ll maxpos(string &s, char c){
	ll cue=0;
	fore(i,0,SZ(s)){
		if(s[i]==c){cue++;
		}else{cue--;
		}
		if(cue==-1)return i+1;
	}
	return 0;
}



int main(){FIN;
	ll n; cin>>n;
	string s; cin>>s;
	ll c=contar(s,'(',n);
	if(n%2){
		cout<<0;
	}else{
		if(c+1==n/2){
			ll p=maxpos(s,'(');
			string t=s; t[p-1]='(';
			if(!maxpos(t,'(')){
				cout<<contar(s,')',p);	
			}else{
				cout<<0;
			}
		}else
		if(c-1==n/2){
			reverse(ALL(s));
			ll p=maxpos(s,')');
			string t=s; t[p-1]=')';
			if(!maxpos(t,')')){
				cout<<contar(s,'(',p);		
			}else{
				cout<<0;
			}
		}else{
			cout<<0;
		}
	}
	
	return 0;
}