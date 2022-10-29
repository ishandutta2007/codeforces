#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

int main(){
	ll r=0;
	int k2,k3,k5,k6;
	cin>>k2>>k3>>k5>>k6;
	while(k2>0&&k5>0&&k6>0){
		k2--;k5--;k6--;
		r+=256;
	}
	while(k2>0&&k3>0){
		k2--;k3--;
		r+=32;
	}
	cout<<r<<endl;
	return 0;
}