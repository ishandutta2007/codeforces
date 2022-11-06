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
	ll n,q; cin>>n>>q;
	ll a[n],l[q],r[q];
	memset(a,0,sizeof a);
	fore(i,0,q){
		cin>>l[i]>>r[i];
		l[i]--; r[i]--;
		fore(j,l[i],r[i]+1){
			a[j]++;
		}
	}
	ll cont[2][n+1],tot=0;
	memset(cont,0,sizeof cont);
/*	fore(i,0,n){
		cout<<a[i]<<" ";
	}
	cout<<"\n";*/
	fore(i,1,n+1){
		if(a[i-1]>0){
			tot++;
		}
				
		cont[0][i]=cont[0][i-1]+(a[i-1]==1);	
				
				
		cont[1][i]=cont[1][i-1]+(a[i-1]==2);	
				
			
			
		
	}
//	cout<<tot<<endl;
/*	fore(j,0,2){
		fore(i,0,n+1){
			cout<<cont[j][i]<<" ";	
		}
		cout<<"\n";
	}*/
	
	ll maxi=0;
	fore(i,0,q){
			fore(j,0,q){
				if(i!=j){
					ll cue=tot+cont[0][l[i]]-cont[0][r[i]+1]+cont[0][l[j]]-cont[0][r[j]+1];
					ll li=max(l[i],l[j]),ri=min(r[i],r[j]);
					if(li<=ri){
						cue+=cont[0][ri+1]-cont[0][li]+cont[1][li]-cont[1][ri+1];
					}
				//cout<<cue<<endl;
					maxi=max(maxi,cue);
				}
				
			}	
		
		
	}
	cout<<maxi;
	
	return 0;
}