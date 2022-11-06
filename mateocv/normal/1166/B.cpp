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

ll maxdiv(ll n){
	ll res=1;
	for(int i=2;i*i<=n;i++){
		if(n%i==0)res=i;
	}
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	ll d=maxdiv(n);
	string aeiou="aeiou";
	if(d>=5&&n/d>=5){
		fore(i,0,d){
			fore(j,0,n/d){
				cout<<aeiou[(i+j)%5];
			}
		}
	}else{
		cout<<-1;
	}
	
	return 0;
}