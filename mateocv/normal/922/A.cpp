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

int main(){FIN;
	ll x,y; cin>>x>>y;
	if(y==0||(x+y)%2==0){
		cout<<"No"; return 0;
	}
	if(x==0&&y==1){
		cout<<"Yes"; return 0;
	}
	if(x==0){
		cout<<"No"; return 0;
	}
	if(y<2){
		cout<<"No"; return 0;
	}
	x--; y-=2;
	x-=y;
	if(x<0){
		cout<<"No"; return 0;
	}
	if(x%2==0){
		cout<<"Yes"; return 0;
	}else{
		cout<<"No"; return 0;
	}
	
	
	return 0;
}