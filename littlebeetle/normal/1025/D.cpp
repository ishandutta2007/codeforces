#include<cstdio>
#include<algorithm>
using namespace std;
const int N=702;
typedef long long ll;
struct P{
	ll k;
	int v;
}a[N];
int n,i,j,k,p;
ll l[N][N],r[N][N],g[N][N],f,t[N][N],s[N];
bool cmp(P u,P v){
	return u.k<v.k;
}
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
ll max(ll x,ll y){
	return x>y?x:y;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i].k);
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			g[i][j]=gcd(a[i].k,a[j].k);
	for(i=1;i<=n;i++)
		s[i]=s[i-1]+1;	
	for(p=0;p<n;p++)
		for(i=1;i+p<=n;i++){
			t[i][j=i+p]=-1;
			for(j=i+p,k=i;k<=j;k++){
				if((k!=i&&!l[i][k-1])||(k!=j&&!r[k+1][j]))continue;
				f=l[i][k-1]+r[k+1][j]+s[j]-s[i-1];
				t[i][j]=max(t[i][j],f);
				if(g[i-1][k]!=1)r[i][j]=max(r[i][j],f);
				if(g[k][j+1]!=1)l[i][j]=max(l[i][j],f);
			}
		}
	printf("%s",t[1][n]>0?"Yes":"No");
	return 0;
}