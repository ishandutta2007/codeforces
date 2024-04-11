#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll a1,a2,k1,k2,n; cin>>a1>>a2>>k1>>k2>>n;
	if(k1<k2){
		swap(k1,k2);
		swap(a1,a2);
	}
	cout<<max(0ll,n-(a1*(k1-1)+a2*(k2-1)))<<" ";
	swap(k1,k2);
	swap(a1,a2);
	cout<<min(a1,n/k1)+min(a2,max(0ll,(n-a1*k1)/k2));
	return 0;
}