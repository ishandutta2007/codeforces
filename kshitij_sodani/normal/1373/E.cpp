//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo t;
llo ans=-1;
void remin(llo aa){
	if(ans==-1){
		ans=aa;
	}
	ans=min(ans,aa);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		llo n,k;
		cin>>n>>k;
		ans=-1;
		for(llo i=0;i<=n;i++){
			llo su=0;
			for(llo j=i;j<=i+k;j++){
				su+=j;
			}
			if(su==n){
				llo cur=0;
				llo le=i;
				llo cot=1;
				cur+=min(9-k,i);
				le-=min(9-k,i);
				while(le>0){
					cot*=10;
					cur+=cot*min(le,(llo)9);
					le-=min(le,(llo)9);
				}
				remin(cur);
			}
		}	
		for(llo i=1;i<=n;i++){
			for(llo j=1;j<=i/9;j++){
				for(llo m=1;m<=k+1;m++){
					llo su=0;
					for(llo kk=0;kk<m;kk++){
						su+=i-kk;
					}
					for(llo kk=0;kk<k+1-m;kk++){
						su+=i-j*9+kk+1;
					}
					if(su==n){
						llo cur=0;
						llo le=i;
						llo cot=1;
						llo xx=0;

						while(le>0){
							xx+=1;
							llo me=9;
							
							if(xx==j+1){
								me=8;
							}
							cur+=min(le,me)*cot;
							le-=min(le,me);
							cot*=10;
						}
						cur-=(m-1);
						/*if(cur==49){
							cout<<i<<":"<<j<<":"<<m<<endl;
						}*/
						remin(cur);
					}
				}
			}
			
		}
		cout<<ans<<endl;
	}







 
	return 0;
}