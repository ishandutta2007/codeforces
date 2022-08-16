//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

pair<llo,llo> it[1000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(llo i=0;i<n;i++){
			cin>>it[i].a;
			it[i].b=i;
		}
		sort(it,it+n);
		llo l=0;
		llo st=1;
		while(l<n){
			llo r=l;
			llo co=0;

			llo co2=0;
			while(r<n){
				if(it[r].a==it[l].a){
					if(r%2==0){
						co++;
					}
					else{
						co2++;
					}
					if(it[r].b%2==0){
						co--;
					}
					else{
						co2--;
					}

					r++;
				}
				else{
					break;
				}
			}
			if(co!=0 or co2!=0){
				st=0;
			}

			l=r;
		}
		if(st){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}



 
 
 
 
 
 
 
	return 0;
}