#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
int a,mn=INT_MAX,mx=INT_MIN,n;
ll ans;
int main(){
	scanf("%d",&n);
	if(n==1){
		scanf("%d",&a);
		printf("%d",a);
	}
	else{
		while(n--)scanf("%d",&a),mn=min(mn,a),mx=max(mx,a),ans+=abs(a);
		printf("%lld",ans-abs(mx)+mx-abs(mn)-mn);
	}
	return 0;
}