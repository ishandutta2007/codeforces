#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

int main(){
	ll n;
	cin>>n;
	ll f=1;
	ll f0=0;
	int r=1;
	while(n>=f){
		ll t=f;
		f+=f0;
		f0=t;
		r++;
	}
	cout<<r-3<<endl;
	return 0;
}