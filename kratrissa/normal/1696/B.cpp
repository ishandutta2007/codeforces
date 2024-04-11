#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,m,z,a[N],ans;
bool all0(){for(int i=1;i<=n;i++)if(a[i])return 0;return 1;}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(all0()){printf("0\n");return;}
	int fp=1,lp=n;
	while(!a[fp])fp++;while(!a[lp])lp--;
	for(int i=fp;i<=lp;i++)if(!a[i]){printf("2\n");return;}
	printf("1\n");return;
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}