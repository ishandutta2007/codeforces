#include <bits/stdc++.h>
#define int long long
using namespace std;
int h[200005];
bool check(int mid,int n){
	int a[n+1],ad[n+1];
	for(int i=1;i<=n;i++){
		a[i]=h[i];
		ad[i]=0;
	} 
	for(int i=n;i>=3;i--){
		if(ad[i]+a[i]<mid){
			return false;
		} 
		int minus=(ad[i]+a[i]-mid);
		if(minus>a[i]){
			minus=a[i];
		}
		minus/=3;
		ad[i-2]+=minus*2;
		ad[i-1]+=minus*1;
	}
	return ((ad[1]+a[1]>=mid)&&(ad[2]+a[2]>=mid));
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>h[i];
		}
		int L=1,R=1e10;
		while(L<R){
			int mid=(L+R)/2;
			if(check(mid,n)){
				L=mid+1;
			}
			else{
				R=mid;
			}
		}
		if(check(L,n)){
			cout<<L<<endl;
		}
		else{
			cout<<L-1<<endl;
		}
	} 
}