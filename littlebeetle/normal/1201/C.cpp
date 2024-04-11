#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200002;
typedef long long ll;
ll n,k,i,a[N],l,r,mid,s;
int main(){
	scanf("%I64d%I64d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%I64d",a+i);
	sort(a+1,a+n+1);
	l=a[n+1>>1];
	r=1ll<<40;
	while(l<r){
		mid=l+r+1>>1;
		s=0;
		for(i=n+1>>1;i<=n;i++)
			if(mid>a[i])
				s+=mid-a[i];
		if(s<=k)
			l=mid;
		else
			r=mid-1;
	}
	printf("%I64d",l);
	return 0;
}