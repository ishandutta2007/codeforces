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
	ll a[3]; cin>>a[0]>>a[1]>>a[2];
	ll res[7]={0,0,0,0,0,0,0};
	ll w=min(a[0]/3,min(a[1]/2,a[2]/2));
	fore(i,0,7)res[i]+=7*w;
	a[0]-=3*w;
	a[1]-=2*w;
	a[2]-=2*w;
	ll b[3];
	fore(i,0,3)b[i]=a[i];
	ll ind[7]={0,1,2,0,2,1,0};
	fore(i,0,7){
		fore(k,0,3)a[k]=b[k];
		fore(j,1,7){
			if(a[ind[(i+j)%7]]>0){
				res[i]++;
				a[ind[(i+j)%7]]--;
			}else{break;
			}
		}
	}
	ll resf=0;
	fore(i,0,7){
		resf=max(resf,res[i]);
	}
	cout<<resf;
	
	return 0;
}