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
int pp[200001];
int ind2[400001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>it[i];
		it[i]--;
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
	for(int i=0;i<100;i++){
		if(i==ind){
			continue;
		}
		for(int j=0;j<=2*n;j++){
			ind2[j]=-1;
		}
		ind2[n]=0;
		for(int j=0;j<n;j++){
			pp[j+1]=pp[j];
			if(it[j]==i){
				pp[j+1]-=1;
			}
			else if(it[j]==ind){
				pp[j+1]+=1;
			}
			/*if(j==9 and i==1){
				cout<<ind2[pp[j+1]+n]<<endl;
			}*/
			if(ind2[pp[j+1]+n]!=-1){
				ans=max(ans,j+1-ind2[pp[j+1]+n]);
			}
			else{
				ind2[pp[j+1]+n]=j+1;
			}

		}

	}
	cout<<ans<<endl;






 
 
	return 0;
}