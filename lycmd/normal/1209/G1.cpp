#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,q,ans,a[N],l[N],r[N],p[N];
set<int>s;
map<int,int>cnt;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i],l[a[i]]=l[a[i]]?l[a[i]]:i,r[a[i]]=i;
	for(int i=1;i<N;i++)
		p[l[i]]++,p[r[i]]--;
	s.erase(0);
	for(int i=1,cur=0,pre=0;i<=n;i++)
		if(s.erase(cnt[a[i]]),s.insert(++cnt[a[i]]),!(cur+=p[i]))
			ans+=i-pre-*s.rbegin(),pre=i,s.clear(),cnt.clear();
	cout<<ans<<"\n";
}