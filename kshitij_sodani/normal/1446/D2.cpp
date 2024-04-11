//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int n;
int it[200001];
int aa[200001];
int mm[200001];
int ind2[400001];
vector<int> pp[200001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>it[i];
		it[i]--;
		pp[it[i]].pb(i);
		aa[it[i]]+=1;
	}
	int ma=0;
	int ind=0;
	for(int i=0;i<n;i++){
		if(aa[i]>ma){
			ma=aa[i];
			ind=i;
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(i==ind){
			continue;
		}
		if(pp[i].size()==0){
			continue;
		}
		if(aa[i]>=300){
			for(int j=0;j<=2*n;j++){
				ind2[j]=-1;
			}
			ind2[n]=0;
			for(int j=0;j<n;j++){
				mm[j+1]=mm[j];
				if(it[j]==i){
					mm[j+1]-=1;
				}
				else if(it[j]==ind){
					mm[j+1]+=1;
				}
				if(ind2[mm[j+1]+n]!=-1){
					ans=max(ans,j+1-ind2[mm[j+1]+n]);
				}
				else{
					ind2[mm[j+1]+n]=j+1;
				}
			}
		}
		else{
			//
			for(int j=0;j<pp[i].size();j++){
				for(int k=j;k<pp[i].size();k++){
			//		cout<<j<<"<<"<<k<<endl;
					int ind2=lower_bound(pp[ind].begin(),pp[ind].end(),pp[i][j])-pp[ind].begin();
					ind2=max(0,ind2-(k-j+1));
					//cout<<ind2<<",,"<<endl;
					for(int l=ind2;l+k-j<pp[ind].size();l++){
						if(l+k-j+1<pp[ind].size()){
							if(pp[ind][l+k-j+1]<pp[i][k]){
								if(pp[ind][l]>pp[i][j]){
									break;
								}
								continue;
							}
						}
						int ll,rr;
						if(k+1<pp[i].size()){
							rr=pp[i][k+1]-1;
						}					
						else{
							rr=n-1;
						}	
						if(l+k-j+1<pp[ind].size()){
							rr=min(rr,pp[ind][l+k-j+1]-1);
						}
						else{
							rr=min(rr,n-1);
						}
						if(j>0){
							ll=pp[i][j-1]+1;
						}
						else{
							ll=0;
						}
						if(l>0){
							ll=max(ll,pp[ind][l-1]+1);
						}
						else{
							ll=max(ll,0);
						}
					//	cout<<ind<<":"<<i<<endl;
					//	cout<<j<<":"<<k<<":"<<l<<":"<<l+k-j<<endl;
					//	cout<<ll<<",,"<<rr<<endl;
					//	cout<<endl;
						ans=max(ans,rr-ll+1);
						if(pp[ind][l]>pp[i][j]){
							break;
						}
					}
				}
			}
		}
	}
	cout<<ans<<endl;






 
 
	return 0;
}