#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,a[N],p[N],t[N],ans[N];
mt19937 rnd(114514);
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],p[i]=i;
	for(int k=233;k--;){
		shuffle(p+1,p+1+n,rnd);
		for(int i=1;i<=n;i++)
			t[i]=a[p[i]];
		int g1=t[ans[p[1]]=1],g2=t[ans[p[2]]=2];
		for(int i=3;i<=n;i++)
			if(t[i]%g1)
				g1=__gcd(g1,t[i]),ans[p[i]]=1;
			else
				g2=__gcd(g2,t[i]),ans[p[i]]=2;
		if(g1==1&&g2==1){
			cout<<"YES\n";
			for(int i=1;i<=n;i++)
				cout<<ans[i]<<" ";
			cout<<"\n",exit(0);
		}
	}
	cout<<"NO\n";
}