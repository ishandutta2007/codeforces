#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n; cin>>n;
	ll llega;
	pair<ll,ll> sum[n+1];
	memset(sum, 0, sizeof sum);
	fore(i,0,n){
		cin>>llega;
		if(i==0){sum[0].fst=llega;
		sum[0].snd=0;
		}else{
			sum[i].fst=sum[i-1].fst^llega;
			sum[i].snd=i%2;
		}
	}
	sum[n].fst=0;
	sum[n].snd=1;
	sort(sum,sum+(n+1));
	ll res=0,van1=-1,van2=0,par=0;
	fore(i,0,n+1){
		if((van1==sum[i].fst)&&(van2==sum[i].snd)){
			par++;
		}else{
			res+=par*(par-1)/2;
			van1=sum[i].fst;
			van2=sum[i].snd;
			par=1;
		}
		if(i==n){
			res+=par*(par-1)/2;
			van1=sum[i].fst;
			van2=sum[i].snd;
			par=1;	
			}
	//	cout<<sum[i].fst<<" "<<sum[i].snd<<"\n";
	}
	cout<<res;
	
	
	return 0;
}