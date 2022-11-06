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
	ll n; cin>>n;
	ll a[n],b[n];
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)cin>>b[i];
	ll c[n];
	mset(c,0);
	fore(i,0,n){
		c[a[i]-1]++;
	}
	ll rep=0;
	fore(i,0,n){
		if(c[i]==2){
			rep=i+1; break;
		}
	}
	ll vac=0;
	fore(i,0,n){
		if(c[i]==0){
			vac=i+1; break;
		}
	}
	ll pos1=-1,pos2=-1;
	fore(i,0,n){
		if(a[i]==rep){
			if(pos1<0){
				pos1=i;
			}else{
				pos2=i;
			}
		}
	}
	ll res[n];
	fore(i,0,n){
		res[i]=a[i];
	}
	res[pos1]=vac;
	ll tot=0;
	fore(i,0,n){
		if(b[i]==res[i])tot++;
	}
	if(tot!=n-1){
		swap(res[pos1],res[pos2]);
	}
	
	fore(i,0,n)cout<<res[i]<<" ";
	
	
	return 0;
}