//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int it[200001];
int n,k;
int pre[200001];
pair<int,int> cur;
bool check(int mid){
	for(int j=mid;j<n;j++){
		int x=pre[j+1]-pre[j-mid];
		if(x-(n-x)>=k){
			cur={j-mid+1,j+1};
			return true;
		}
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		
		cin>>n>>k;
		for(int i=0;i<=n;i++){
			pre[i]=0;
		}
		for(int i=0;i<n;i++){
			cin>>it[i];
			pre[it[i]]++;
		}
		for(int i=1;i<=n;i++){
			pre[i]+=pre[i-1];
		}
		int low=n-1;
		cur={1,n};
		for(int j=19;j>=0;j--){
			if(low-(1<<j)>=0){
				if(check(low-(1<<j))){
					low-=(1<<j);
				}
			}
		}
		vector<int> kk;
		int su=0;
		int ind=1;
		for(int i=0;i<n;i++){
			if(ind==k){
				break;
			}
			if(it[i]>=cur.a and it[i]<=cur.b){
				su++;
			}
			else{
				su--;
			}
			if(ind==su){
				kk.pb(i);
				ind++;
				if(ind==k){
					break;
				}
			}

		}
		kk.pb(n-1);
		//cout<<low<<endl;
		cout<<cur.a<<" "<<cur.b<<endl;
		for(int j=0;j<kk.size();j++){
			if(j==0){
				cout<<1<<" "<<kk[j]+1<<endl;
			}
			else{
				cout<<kk[j-1]+2<<" "<<kk[j]+1<<endl;
			}
		}

	}




 
	return 0;
}