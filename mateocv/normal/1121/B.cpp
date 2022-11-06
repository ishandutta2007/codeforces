#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n){
		cin>>a[i];
	}
	ll sum[200002];
	memset(sum,0,sizeof sum);
	fore(i,0,n){
		fore(j,i+1,n){
			sum[a[i]+a[j]]++;
		}
	}
	ll maxi=0;
	fore(i,0,200001){
		maxi=max(maxi,sum[i]);
	}
	cout<<maxi;
	return 0;
}