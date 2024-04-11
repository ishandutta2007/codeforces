#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

ll r;
ll b,d,s;

void doit(ll b, ll d, ll s){
	ll x=max(b,max(d,s));
	r=min(r,x-b+x-d+x-s);
}

int main(){
	r=(1LL<<63)-1;
	cin>>b>>d>>s;
	doit(b,d,s);
	doit(b+1,d,s);
	doit(b+1,d+1,s);
	doit(b,d,s+1);
	doit(b+1,d,s+1);
	doit(b+1,d+1,s+1);
	doit(b,d+1,s+1);
	doit(b+1,d+1,s+1);
	doit(b+1,d+2,s+1);
	cout<<r<<endl;
	return 0;
}