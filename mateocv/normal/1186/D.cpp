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

ll prob[100005];

int main(){FIN;
	ll n; cin>>n;
	long double a[n];
	ll b[n];
	fore(i,0,n)cin>>a[i];
	fore(i,0,n){
		if(1*floor(a[i])==1*ceil(a[i]))prob[i]=1;
		b[i]=ceil(a[i]);
	}
	ll sum=0;
	fore(i,0,n){
		sum+=b[i];
	}
	if(sum!=0){
		fore(i,0,n){
			if(prob[i]==0){
				b[i]--;
				sum--;
				if(sum==0)break;
			}
		}
	}
	fore(i,0,n)cout<<b[i]<<"\n";
	
	return 0;
}