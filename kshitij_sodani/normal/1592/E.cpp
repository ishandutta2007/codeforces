//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int it[1000001];
int pre[1000001];
int cur[1000001];
map<int,int> kk[2];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>it[i];
	}
	int ans=0;
	for(int i=19;i>=0;i--){
		for(int j=0;j<n;j++){
			if(1+i<=19){
				cur[j]+=((1<<(i+1))&it[j]);
			}
			pre[j+1]=pre[j]^cur[j];
		}
		kk[0].clear();
		kk[1].clear();
		for(int j=0;j<n;j++){
			if((1<<i)&it[j]){

				if((kk[1-(j%2)]).find(pre[j+1])!=(kk[1-(j%2)]).end()){
					ans=max(ans,j-kk[1-(j%2)][pre[j+1]]+1);
				}
				if(kk[j%2].find(pre[j])==kk[j%2].end()){
					kk[j%2][pre[j]]=j;
				}
			}
			else{
				kk[0].clear();
				kk[1].clear();
			}
		}
	}
	cout<<ans<<endl;



 
 
 
	return 0;
}