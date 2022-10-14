#include<bits/stdc++.h>
using namespace std;
int const N=2333;
int n,ans,a[N];
map<int,int>s,t;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],s[a[i]]++;
	sort(a+1,a+1+n),ans=max(2,s[0]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j&&a[i]|a[j]){
				if(i>1&&a[i-1]==a[i])
					break;
				t.clear(),t[a[i]]++,t[a[j]]++;
				int a1=a[i],a2=a[j],a3=a[i]+a[j],res=2;
				while(t[a3]<s[a3])
					t[a3]++,a1=a2,a2=a3,a3=a1+a2,res++;
				ans=max(ans,res);
			}
	cout<<ans<<"\n";
}