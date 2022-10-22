#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
typedef long long ll;
int T,n,r,b;
void solve(){
	scanf("%d%d%d",&n,&r,&b);
	int t=(r-1)/(b+1),w=(r-1)%(b+1)+1;
	for(int i=1;i<=b+1;i++){
		for(int j=1;j<=t+(i<=w);j++)putchar('R');
		if(i!=b+1)putchar('B');
	}
	putchar('\n');
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}