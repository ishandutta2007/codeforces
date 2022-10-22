#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n;
void solve(){
	scanf("%d",&n);
	int mx=0,mx2=0;
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		if(x>mx)mx2=mx,mx=x;
		else if(x>mx2)mx2=x;
	}
	printf("%d\n",mx+mx2);
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}