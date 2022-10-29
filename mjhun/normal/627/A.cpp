#include <bits/stdc++.h>
#define mp make_pair
#define fst first
#define snd second
using namespace std;

typedef long long ll;

ll f(ll s, ll x){
	if(s<0)return 0;
	if(!s)return x==0;
	if(x&1)return (s&1)?2*f(s>>1,x>>1):0;
	return (s&1)?0:f(s>>1,x>>1)+f((s>>1)-1,x>>1);
}

int main(){
	ll s,x;
	cin>>s>>x;
	cout<<f(s,x)-(s==x?2:0)<<endl;
	return 0;
}