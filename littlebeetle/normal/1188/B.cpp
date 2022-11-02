#include<cstdio>
#include<map>
using namespace std;
int n,a,b,p,k;
long long ans;
map<int,int>s;
int main(){
	scanf("%d%d%d",&n,&p,&k);
	while(n--){
		scanf("%d",&a);
		b=1ll*a*a%p;
		b=1ll*b*b%p;
		b=(b-1ll*a*k)%p;
		b=(b+p)%p;
		ans+=s[b];
		s[b]++;
	}
	printf("%I64d",ans);
	
}