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

char change(char c){
	return 'B'+('W'-'B')*(c=='B');
}

int main(){FIN;
	ll n; cin>>n;
	string s; cin>>s;
	string t=s;
	vector<ll> v;
	fore(i,0,SZ(t)-1){
		if(t[i]!='B'){
			v.pb(i);
			t[i]=change(t[i]);
			t[i+1]=change(t[i+1]);
		}
	}
	if(t.back()=='B'){
		cout<<SZ(v)<<"\n";
		fore(i,0,SZ(v))cout<<v[i]+1<<" ";
		return 0;
	}
	t=s;
	v.clear();
	fore(i,0,SZ(t)-1){
		if(t[i]!='W'){
			v.pb(i);
			t[i]=change(t[i]);
			t[i+1]=change(t[i+1]);
		}
	}
	if(t.back()=='W'){
		cout<<SZ(v)<<"\n";
		fore(i,0,SZ(v))cout<<v[i]+1<<" ";
		return 0;
	}
	cout<<-1;
	return 0;
}