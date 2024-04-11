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
	ll n,k; cin>>n>>k;
	string s;
	ll a[n-k+1],res[n],ex=-1;
	memset(res,0,sizeof res);
	fore(i,0,n-k+1){
		cin>>s;
		if(s=="YES"){
			a[i]=1;
			if(ex==-1)ex=i;
		}else{
			a[i]=0;
		}
	}
	ll vac=1;
	if(ex!=-1){
		fore(i,ex,ex+k){
			res[i]=i-ex+1;
		}
		vac=k+1;
		fore(i,ex+1,n-k+1){
			if(a[i]){
				res[i+k-1]=vac;
				vac++;
			}else{
				res[i+k-1]=res[i];
			}
		}
		for(int i=ex-1;i>=0;i--){
			if(a[i]){
				res[i]=vac;
				vac++;
			}else{
				res[i]=res[i+k-1];
			}
		}
	}
	string nom[52];
	fore(i,0,52){
		if(i<=25){
			nom[i]+='A';
		}else{
			nom[i]+='B';	
		}
		nom[i]+=('a'+i%26);
	}
	fore(i,0,n){
		cout<<nom[res[i]]<<" ";
	}
	
	
	return 0;
}