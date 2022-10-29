#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

ll n,m;
ll kmin,kmax;

ll c2(ll n){
	return n*(n-1)/2;
}

int main(){
	cin>>n>>m;  // n personas, m equipos
	kmax=c2(n-m+1);
	ll k=n/m;
	kmin=n%m*c2(k+1)+(m-n%m)*c2(k);
	cout<<kmin<<' '<<kmax<<endl;
	return 0;
}