#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

vector<ll> v;

int main(){
	fore(_,0,3){
		ll a;
		cin>>a;v.pb(a);
	}
	sort(v.begin(),v.end());
	if(v[2]>2*(v[0]+v[1]))v[2]=2*(v[0]+v[1]);
	cout<<(v[0]+v[1]+v[2])/3<<endl;
	return 0;
}