#include<bits/stdc++.h>
using namespace std;
int const N=1010;
int n,l,x[N],b[N],pre[N];
double f[N];
vector<int>ans;
int check(double k){
	memset(f,0x42,sizeof f),f[0]=0;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<=n;j++){
			double t=f[i]+sqrtl(abs(x[j]-x[i]-l))*k-b[j];
			if(f[j]>t)f[j]=t,pre[j]=i;
		}
	return f[n]>=0;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>l;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>b[i];
	double l=0.0,r=2e9;
	while(l<r-1e-6){
		double mid=(l+r)/2.0;
		if(check(mid))r=mid;else l=mid;
	}
	for(int i=n;i;i=pre[i])
		ans.push_back(i);
	reverse(ans.begin(),ans.end());
	for(int i:ans)
		cout<<i<<" ";
	cout<<"\n";
}