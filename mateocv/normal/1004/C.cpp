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
	ll n,lle; cin>>n;
	pair<ll,ll> a[100005];
	ll b[n];
	memset(a,-1,sizeof a);
	//ll va=0;
	fore(i,0,n){
		cin>>lle;
		if(a[lle].fst==-1){
			a[lle].fst=i;
		}else{
			a[lle].snd=i;
		}
		b[i]=lle;
	//	va++;
	}
	ll prin[n],fin[n];
	prin[0]=0; fin[n-1]=0;
	fore(i,0,n-1){
		prin[i+1]=prin[i]+(a[b[i]].fst==i);
		fin[n-2-i]=fin[n-1-i]+((a[b[n-1-i]].snd==n-1-i)||(a[b[n-1-i]].snd==-1&&a[b[n-1-i]].fst==n-1-i));
	}
	ll res=0;
	fore(i,0,n){
		if(i==a[b[i]].fst||i==a[b[i]].snd){
			if(a[b[i]].fst==i){
				if(a[b[i]].snd==-1){
					res+=prin[i]+fin[i];
				}else{
					res+=fin[i];
				}
			}else{
				res+=prin[i];
			}	
		}
	}
	
	/*fore(i,0,n){
		cout<<prin[i]<<" ";
	}
	cout<<"\n";
	fore(i,0,n){
		cout<<fin[i]<<" ";
	}
	cout<<"\n";*/
	cout<<res/2;
	return 0;
}