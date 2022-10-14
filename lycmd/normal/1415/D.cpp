#include<bits/stdc++.h>
using namespace std;
int const N=2333333,INF=0x3f3f3f3f;
int n,ans=INF,a[N],xs[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],xs[i]=xs[i-1]^a[i];
	if(n>60){
		cout<<"1\n";
		return 0;
	}
	for(int d=1;d<=n;d++)
		for(int l=1;l<=n-d+1;l++){
			int r=l+d-1;
			for(int p=l;p<r;p++)
				if((xs[r]^xs[p])<(xs[p]^xs[l-1])){
					ans=d-2;goto finish;
				}
		}
finish:
	cout<<(ans<INF?ans:-1)<<"\n";
}