#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int dist[100005];
		for(int i=0;i<=n*m;i++){
			dist[i]=0;
		}
		if(n%2==1&&m%2==1){
			int midx=n/2+1,midy=m/2+1;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					dist[llabs(i-midx)+llabs(j-midy)]++;
				}
			}
		}
		else if(n%2==0&&m%2==0){
			int midx=n/2,midy=m/2;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					int ri=min(i,n-i+1),rj=min(j,m-j+1);
					dist[llabs(ri-midx)+llabs(rj-midy)]++;
				}
			}
		}
		else{
			if(m%2==0){
				swap(n,m);
			}
			int midx=n/2,midy=m/2+1;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					int ri=min(i,n-i+1),rj=min(j,m-j+1);
					dist[llabs(ri-midx)+llabs(rj-midy)]++;
				}
			}
		}
		int midx=n/2+1,midy=m/2+1;
		int distl=llabs(midx-1)+llabs(midy-1);
		for(int i=0;i<=n*m;i++){
			for(int j=1;j<=dist[i];j++){
				cout<<distl<<" ";
			}
			distl++;
		}
		cout<<endl;
	}
	return 0;
}