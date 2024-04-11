#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,k,cnt; ll a[105],s[100005];
map<ll,int> mp;
int main(){
	scanf("%d%d",&n,&k);int i,j;long long ans=0;
	for (i=1; i<=n; i++){
		int x;scanf("%d",&x); s[i]=s[i-1]+x;
	}
	if (k==1) a[cnt=1]=1; else
	if (k==-1){ a[cnt=2]=-1; a[1]=1; } else {
		a[cnt=1]=1;
		while (abs(a[cnt])<1000000000000000ll){
			cnt++;a[cnt]=a[cnt-1]*k;
		}
	}
	mp[s[0]]++;
	for (i=1; i<=n; i++){
		for (j=1; j<=cnt; j++) ans+=mp[s[i]-a[j]];
		mp[s[i]]++;
	}cout<<ans<<endl;
	return 0;
}