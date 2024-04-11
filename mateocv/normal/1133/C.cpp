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
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	ll res[n], va=-1;
	memset(res,0,sizeof res);
	ll topp=0;
	fore(i,0,n){
		if(va==-1)va=a[0];
		if(i==0){
			fore(j,0,n){
				if(a[j]<=va+5){res[0]++; topp++;}else{break;}
			}
		}else
		if(a[i]>va){
		res[i]=res[i-1]-1;
			va=a[i];
			ll tope=topp;
			fore(j,topp,n){
				if(a[j]<=va+5){
					res[i]++;
		//			cout<<a[j]<<"para el "<<i<<"\n";
					tope++;
				}else{
					break;
				}
				
			}
			topp=tope;
			
		}else{
			res[i]=res[i-1]-1;
		}
	}
	
	ll maxi=0;
	fore(i,0,n){
		maxi=max(maxi,res[i]);
		//cout<<res[i]<<" ";
	}
	//cout<<"\n";
	cout<<maxi;
	
	return 0;
}