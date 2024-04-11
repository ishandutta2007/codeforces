#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=5000;
int n,m;
int a[N],b[N];
bool f[N][N][2];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);m=n<<1;
		for(int i=1;i<=m;++i) b[i]=0;
		int mx=0;
		for(int i=1;i<=m;++i) {
			scanf("%d",&a[i]);
			if(a[i]>mx){
				mx=a[i];
				b[i]=1;
			}
		}
		f[0][0][0]=1;f[0][0][1]=1;
		for(int i=1;i<=m;++i){
			for(int j=0;j<=n;++j){
				if(j>i) continue;
				if(i>1&&b[i]){
					if(j>=1) f[i][j][0]|=f[i-1][j-1][1];
					f[i][j][1]|=f[i-1][j][0];
				} 
				if(j>=1) f[i][j][0]|=f[i-1][j-1][0];
				f[i][j][1]|=f[i-1][j][1];
			}
			//for(int j=0;j<=n;++j) cout<<i<<" "<<j<<" "<<f[i][j][0]<<" "<<f[i][j][1]<<endl;
		}
		if(f[m][n][0]||f[m][n][1]) printf("YES\n");
		else printf("NO\n");
		for(int i=0;i<=m;++i) for(int j=0;j<=n;++j) f[i][j][0]=f[i][j][1]=0;
	}
	return 0;
}