#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int T,n,a[N];
bool check0(){for(int i=1;i<n;i++)if(a[i]==a[i+1])return 0;return 1;}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(check0()){printf("0\n");return;}
	int fp,lp;
	for(fp=1;a[fp]!=a[fp+1];fp++);
	for(lp=n;a[lp]!=a[lp-1];lp--);
	if(lp-fp==1)printf("0\n");
	else if(lp-fp==2)printf("1\n");
	else printf("%d\n",lp-fp-2);
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}