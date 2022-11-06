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

void fin(){
	cout<<"Infinite"; exit(0);
}

int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ll res=0;
	fore(i,1,n){
		if(a[i]==3){
			if(a[i-1]==1)res+=4;
			if(a[i-1]==2)fin();
		}else if(a[i]==2){
			if(a[i-1]==1){
				if(i>=2&&a[i-2]==3){res+=2;
				}else{
					res+=3;
				}
			}
			if(a[i-1]==3)fin();
		}else if(a[i]==1){
			if(a[i-1]==2)res+=3;
			if(a[i-1]==3)res+=4;
		}
	}
	cout<<"Finite\n"<<res;
	return 0;
}