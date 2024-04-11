#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1001001;
double a[N];
const int L=20;
double pre[N];
int nxt[N][L];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=x;
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=0;i<L;i++)nxt[n+1][i]=n+1;
	for(int i=n;i>=1;i--){
		int x=i+1;
		while(x<=n&&nxt[x][0]<=n){
			int y=nxt[x][0];
			if((pre[x]-pre[i])/(x-i)<(pre[y]-pre[x])/(y-x)){
				break;
			}
			x=y;
		}
		// cerr<<"nxt "<<i<<" "<<x<<endl;
		nxt[i][0]=x;
		for(int j=1;j<L;j++){
			nxt[i][j]=nxt[nxt[i][j-1]][j-1];
		}
	}
	double b=0;
	int r=1;
	for(int i=1;i<=n;i++){
		int x=max(r,i);
		for(int j=L-1;j>=0;j--){
			int y=nxt[x][j];
			int z=nxt[y][0];
			if(z!=n+1){
				double ay=(pre[y]+b)/(y-i+1);
				double az=(pre[z]+b)/(z-i+1);
				if(az<ay){
					// cerr<<"x => "<<y<<endl;
					x=y;
				}
			}
		}
		int y=nxt[x][0];
		if(y!=n+1){
			double ax=(pre[x]+b)/(x-i+1);
			double ay=(pre[y]+b)/(y-i+1);
			if(ay<ax){
				// cerr<<"x => "<<y<<endl;
				x=y;
			}
		}
		// cerr<<i<<" "<<x<<endl;
		double ans=(pre[x]+b)/(x-i+1);
		printf("%.12lf\n",ans);
		r=x;
		b-=ans;
	}
	return 0;
}