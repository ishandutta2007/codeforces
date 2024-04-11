#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1005;
int n;
double p;
int c[MAXN][4];
bool Check(int k){
	double s=c[k][3]+c[k][2]*(n-k)+(double)(k)*c[n-k][2]/2;
	return s/c[n][3]>=p;
}
int main(){
	scanf("%d%lf",&n,&p);
	for(int i=0; i<=n; i++){
		c[i][0]=1;
		for(int j=1; j<4&&j<=i; j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	int l=0,r=n-1;
	while(l<r){
		int mid=l+r>>1;
		if(Check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",r);
	return 0;
}