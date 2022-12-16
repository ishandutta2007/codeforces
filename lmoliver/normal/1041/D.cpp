#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200200;
int l[N],s[N],e[N],sf[N];
int main(){
	int n,h;
	cin>>n>>h;
	for(int i=0;i<n;i++){
		scanf("%d%d",&s[i],&e[i]);
		l[i]=e[i]-s[i];
	}
	for(int i=0;i<n;i++){
		sf[i]=i?sf[i-1]+l[i]:l[i];
	}
	int ans=0;
	for(int i=0;i<n;i++){
		int l=i,r=n-1;
		while(l<r){
			bool ok;
			int mid=(l+r+1)/2;
			//can reach mid?
			int boost=sf[mid-1]-sf[i];
			ok=e[i]+boost+h>s[mid];
			if(ok){
				l=mid;
			}else{
				r=mid-1;
			}
		}
		int lsf=i?sf[i-1]:0;
		int tans=sf[l]-lsf+h;
		ans=max(ans,tans);
	}
	cout<<ans;
	return 0;
}