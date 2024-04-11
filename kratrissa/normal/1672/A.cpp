#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=55;
int T,n,sg[N];bool vst[128];
void solve(){
	scanf("%d",&n);int xs=0;
	for(int i=1,x;i<=n;i++)scanf("%d",&x),xs^=sg[x];
	printf(xs?"errorgorn\n":"maomao90\n");
}
int main(){
	for(int i=2;i<=55;i++){
		fill(vst,vst+i+1,0);
		for(int j=1;j<i;j++)vst[sg[j]^sg[i-j]]=1;
		for(sg[i]=0;vst[sg[i]];sg[i]++);
	}
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}