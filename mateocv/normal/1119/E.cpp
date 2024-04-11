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
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n){
		cin>>a[i];
	}
	ll res=0; ll va=1;
	fore(i,0,n){
		res+=a[i]/3;
		//cout<<a[i]/3<<" de "<<i<<" "<<i<<" "<<i<<"\n";
		a[i]-=(a[i]/3)*3;
		if(a[i]>0){
			while((a[va]<2||i==va)&&va<n)va++;
			if(va!=n){
				res++; a[va]-=2; a[i]--;
				//cout<<"1 de "<<va<<" "<<va<<" "<<i<<"\n";
				if(a[i]>0){
					while((a[va]<2||i==va)&&va<n)va++;
					if(va!=n){
						res++; a[va]-=2; a[i]--;
						//cout<<"1 de "<<va<<" "<<va<<" "<<i<<"\n";
					}
				}
			}
		}

		
	}
	cout<<res;
	
	return 0;
}