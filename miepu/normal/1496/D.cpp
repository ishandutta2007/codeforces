#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

int n;
int p[N];
int ld[N],lu[N],rd[N],ru[N];
int mx1[N],mx2[N];

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	ld[1]=lu[1]=1;
	for(int i=2;i<=n;i++){
		if(p[i]>p[i-1]){
			ld[i]=ld[i-1];
			lu[i]=i;
		}else{
			lu[i]=lu[i-1];
			ld[i]=i;
		}
	}
	rd[n]=ru[n]=n;
	for(int i=n-1;i;i--){
		if(p[i]>p[i+1]){
			rd[i]=rd[i+1];
			ru[i]=i;
		}else{
			ru[i]=ru[i+1];
			rd[i]=i;
		}
	}
	
	for(int i=1;i<=n;i++){
		mx1[i]=max({mx1[i-1],i-ld[i]+1,i-lu[i]+1});
	}
	
	for(int i=n;i>=1;i--){
		mx2[i]=max({mx2[i+1],rd[i]-i+1,ru[i]-i+1}); 
	} 
	
	int res=0;
	for(int i=1;i<=n;i++){
		if(ld[i]==i||rd[i]==i){
			continue;
		}// only one direction
		
		if(i-ld[i]!=rd[i]-i){
			continue;
		}
		
		if((i-ld[i])&1){
			continue;
		}
		
		if(i-ld[i]+1<=mx1[ld[i]]||i-ld[i]+1<=mx2[rd[i]])
			continue;
		
		res++;
		
	}
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;//cin>>_T;
	while(_T--)solve();
	
}