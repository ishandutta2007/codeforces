#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define MOD 1000000007
using namespace std;

typedef long long ll;

int c[1024][1024];

int main(){
	fore(i,0,1024){
		c[i][0]=c[i][i]=1;
		fore(j,1,i)c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
	}
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	if(2*k>=min(n,m))puts("0");
	else printf("%d\n",(int)((1LL*c[n-1][2*k]*c[m-1][2*k])%MOD));
	return 0;
}