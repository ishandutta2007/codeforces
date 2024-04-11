#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define MOD 1000000007
using namespace std;

typedef long long ll;

int n,a,b,k;
int f[5005];
int ft[5005];

int main(){
	scanf("%d%d%d%d",&n,&a,&b,&k);
	fore(i,1,n+1)f[i]=1;
	while(k--){
		memcpy(ft,f,sizeof(f));
		fore(i,1,n+1)ft[i]+=ft[i-1],ft[i]%=MOD;
		fore(i,1,n+1){
			int x,y;
			x=max(i-abs(i-b)+1,1);
			y=min(i+abs(i-b)-1,n);
			f[i]=(MOD-f[i])%MOD;
			f[i]+=ft[y];f[i]%=MOD;
			f[i]=(f[i]+MOD-ft[x-1])%MOD;
		}
	}
	printf("%d\n",f[a]);
	return 0;
}