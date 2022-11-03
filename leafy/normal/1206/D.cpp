#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n;
ll a[N];
int mp[1005][1005];
int b[1005];
int dis[1005][1005];
signed main(){
	scanf("%d",&n);
	int m=0;
	for(int i=1;i<=n;i++) {
		m++;
		scanf("%I64d",&a[m]);
		if(a[m]==0) m--;
	}
	n=m;
	if(n>=500){
		puts("3");
		return 0;
	}
	memset(dis,0x3f,sizeof(dis));
	memset(mp,0x3f,sizeof(mp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			if(i!=j&&(a[i]&a[j]))
				dis[i][j]=mp[i][j]=1;
	}
	int ans=0x3f3f3f3f;
	for(int k=1;k<=n;k++){
		for(int i=1;i<k;i++){
			for(int j=i+1;j<k;j++){
				ans=min((long long)ans,(long long)dis[i][j]+(long long)mp[j][k]+(long long)mp[k][i]);
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	if(ans!=0x3f3f3f3f) cout<<ans;
	else cout<<-1;
	return 0;
}