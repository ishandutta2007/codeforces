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

bool comp(pair<pair<ll,ll>,ll> a,pair<pair<ll,ll>,ll> b){
	return a.fst.fst*b.fst.snd>a.fst.snd*b.fst.fst;
}

ll solve(string &s){
	ll res=0;
	ll h=count(ALL(s),'h');
	fore(i,0,SZ(s)){
		if(s[i]=='s'&&h>0)res+=h;
		else h--;
	}
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	string s[n];
	fore(i,0,n)cin>>s[i];
	pair<pair<ll,ll>,ll> a[n];
	fore(i,0,n){
		a[i].fst.fst=count(ALL(s[i]),'s');
		a[i].fst.snd=count(ALL(s[i]),'h');
		a[i].snd=i;
	}
	sort(a,a+n,comp);
	string t;
	fore(i,0,n){
		t+=s[a[i].snd];
	}
//	cout<<t<<"\n";
	cout<<solve(t);
	
	return 0;
}