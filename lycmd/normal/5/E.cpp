#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=1000010;
int n,ans,a[N],s[N],b[N],cnt[N];
signed main(){
    ios::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int top=0,p=0;ans+=n-1;
	for(int i=1;i<n;i++)
		if(a[i]>a[p])p=i;
	for(int i=1;i<n;i++)
		b[i]=a[(p+i)%n];
	for(int i=0;i<n;i++){
		while(top&&s[top]<b[i])
			ans+=cnt[top--];
		if(s[top]^b[i])
			s[++top]=b[i],cnt[top]=0;
		ans+=cnt[top]++;
	}
	while(top>1)
		ans+=cnt[top--];
	cout<<ans<<"\n";
}