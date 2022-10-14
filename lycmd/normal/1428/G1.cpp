#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=1000010,K=N-10,pw[]={3,30,300,3000,30000,300000};
int n,q,x,a[N],f[N];
void add(int w,int v){
	for(int i=K;i>=w;i--)
		f[i]=max(f[i],f[i-w]+v);
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n,n=3*n-3;
	for(int i=0;i<6;i++)
		cin>>a[i];
	for(int i=0;i<K;i++)
		for(int j=0,w=i;w;j++,w/=10)
			f[i]+=((w%10)%3==0)*(w%10)/3*a[j];
	for(int i=0;i<6;i++){
		int t=min(n,K/pw[i]);
		for(int j=1;j<t;j<<=1)
			t-=j,add(pw[i]*j,a[i]*j);
		add(pw[i]*t,a[i]*t);
	}
	for(cin>>q;q--;)
		cin>>x,cout<<f[x]<<"\n";
}