#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

int ma[100001];
int aa[100001];
int ss[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=0;i<=100000;i++){
			ma[i]=i;
		}
		int ans=100000;
		for(int i=0;i<n;i++){
			cin>>aa[i];
			llo ind=0;
			int zz=0;
			for(int j=1;j*j<=aa[i];j++){
				zz=j;
				if((aa[i]/j)<=k or (aa[i]/k)==j){
					ss[ind]=j;
					ind++;
				}
				
			}
			for(int j=zz;j>=1;j--){
				if(j<=k){
					ss[ind]=(aa[i]/j);
					ind++;
				}
			}
			ma[0]=max(ma[0],ss[0]);
			for(int j=1;j<ind;j++){
				if(ss[j]==ss[j-1]){
					continue;
				}
				ma[ss[j-1]+1]=max(ma[ss[j-1]+1],ss[j]);
			}
			/*for(int j=0;j<ind;j++){
				cout<<ss[j]<<",";
			}
			cout<<endl;*/
		}
		for(int i=1;i<=1e5;i++){
			ma[i]=max(ma[i],ma[i-1]);
		}
		for(int i=0;i<=aa[0];i++){
			ans=min(ans,ma[i]-i);
		}
		cout<<ans<<endl;


	}






	return 0;
}