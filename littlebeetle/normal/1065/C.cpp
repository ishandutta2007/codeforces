#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200002;
int n,k,a,i,p;
long long s,g,f[N];
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%d",&a),f[a]++;
	for(i=N-1;i&&g!=n;i--){
		g+=f[i];
		if(s+f[i]*i-g*(i-1)>k)
			s=g*i,p++;
		else
			s+=f[i]*i;
	}
	if(s!=1ll*(i+1)*n)
		p++;
	printf("%d",p);
}