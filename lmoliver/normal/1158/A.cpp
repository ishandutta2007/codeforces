#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100100;
int b[N],g[N];
LL ans=0;
void GG(){
	puts("-1");
	exit(0);
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int mb1=0;
	int mb2=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		ans+=(LL)b[i]*m;
		if(b[i]>mb2)mb2=b[i];
		if(mb2>mb1)swap(mb2,mb1);
	}
	bool add=true;
	for(int i=1;i<=m;i++){
		scanf("%d",&g[i]);
		if(g[i]<mb1)GG();
		if(g[i]>mb1){
			ans+=g[i]-mb1;
		}
		else{
			add=false;
		}
	}
	if(add){
		if(n<2||m<2)GG();
		else ans+=mb1-mb2;
	}
	cout<<ans<<endl;
	return 0;
}