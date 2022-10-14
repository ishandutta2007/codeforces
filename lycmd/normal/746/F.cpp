#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,w,k,sum,cur,ans,a[N],t[N];
multiset<int>s1,s2;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>w>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>t[i];
	int l=1,r=0;
	while(r<n){
		while(r<n){
			r++;
			int s1b=*s1.begin();
			if(s1.size()<w&&sum+(t[r]+1)/2<=k)s1.insert(t[r]),sum+=(t[r]+1)/2;
			else if(t[r]>s1b&&sum+s1b-(s1b+1)/2+(t[r]+1)/2<=k){
				s2.insert(s1b),s1.erase(s1.find(s1b)),s1.insert(t[r]);
				sum+=s1b-(s1b+1)/2+(t[r]+1)/2;
			}else if(sum+t[r]<=k)s2.insert(t[r]),sum+=t[r];
			else{r--;break;} 
			ans=max(ans,cur+=a[r]);
		}
		if(!s1.size()){r++;continue;}
		else if(!s2.size())s1.erase(s1.find(t[l])),sum-=(t[l]+1)/2;
		else if(t[l]<*s1.begin())s2.erase(s2.find(t[l])),sum-=t[l];
		else{
			int tmp=*s2.rbegin();
			s1.erase(s1.find(t[l])),s1.insert(tmp),s2.erase(s2.find(tmp));
			sum-=(t[l]+1)/2-(tmp+1)/2+tmp;
		}
		cur-=a[l++];
	}
	cout<<ans<<"\n";
}