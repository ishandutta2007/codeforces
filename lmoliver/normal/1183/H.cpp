#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=111;
char s[N];
LL cnt[N][N]={0};
int main(){
	LL n,k;
	cin>>n>>k;
	LL _k=k;
	cin>>(s+1);
	for(int i=n;i>=0;i--){
		cnt[i][0]=1;
		for(int c='a';c<='z';c++){	
			for(int j=i+1;j<=n;j++){
				if(s[j]==c){
					for(int k=0;k<n;k++){
						LL &cc=cnt[i][k+1];
						cc=min(_k,cc+cnt[j][k]);
					}
					break;
				}
			}
		}
	}
	LL ans=0;
	for(int i=n;i>=0;i--){
		LL cc=min(k,cnt[0][i]);
		ans+=(n-i)*cc;
		k-=cc;
	}
	if(k>0)puts("-1");
	else cout<<ans<<endl;
	return 0;
}