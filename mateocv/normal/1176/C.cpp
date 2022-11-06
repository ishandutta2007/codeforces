#include <bits/stdc++.h>
#define pb push_back
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
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ll d[6]={4,8,15,16,23,42};
	ll m[50];
	fore(i,0,6)m[d[i]]=i;
	ll c[6]={0,0,0,0,0,0};
	fore(i,0,n){
		if(a[i]==4){
			c[0]++; continue;
		}
		if(c[m[a[i]]-1]>c[m[a[i]]])c[m[a[i]]]++;
	}
	cout<<n-c[5]*6;
	
	return 0;
}