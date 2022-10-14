#include<bits/stdc++.h>
using namespace std;
int const N=4000010;
int n,m,h[N],ans[N];
string s,t;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>t,m=(n+1)/2,s+='#';
	for(int i=0;i<n*2;i++)
		s+='$',s+=t[i&1?n-i/2-1:i/2];
	s+='|';
	for(int i=1,mx=0,p=0;i<s.size();i++){
		h[i]=i<mx?min(mx-i,h[p+p-i]):1;
		while(s[i+h[i]]==s[i-h[i]])h[i]++;
		if(h[i]+i>mx)mx=h[i]+i,p=i;
	}
	memset(ans,-1,sizeof ans);
	for(int i=n/2*4-1,p=m;i>1;i-=4)
		for(p=min(p,i/4+1);p>i/4+1-(h[i]+1)/4;)
			p--,ans[p]=i/2-p*2;
	for(int i=0;i<m;i++)
		cout<<ans[i]<<" ";
	cout<<"\n";
}