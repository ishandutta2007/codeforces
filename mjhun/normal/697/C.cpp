#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
using namespace std;

typedef long long ll;

map<ll,ll> c;

int main(){
	int q;
	scanf("%d",&q);
	while(q--){
		int t;
		cin>>t;
		if(t==1){
			ll x,y,w;
			cin>>x>>y>>w;
			while(x!=y){
				if(x>y)swap(x,y);//x<y
				c[y]+=w;
				y>>=1;
			}
		}
		else {
			ll x,y,r=0;
			cin>>x>>y;
			while(x!=y){
				if(x>y)swap(x,y);//x<y
				r+=c[y];
				y>>=1;
			}
			cout<<r<<endl;
		}
	}
	return 0;
}