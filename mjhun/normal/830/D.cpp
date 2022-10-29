#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define MOD 1000000007
using namespace std;
typedef long long ll;

int add(int a, int b){return (a+b)%MOD;}
int mul(int a, int b){return (1LL*a*b)%MOD;}

int f[512],f2[512];

int main(){
	int n;
	scanf("%d",&n);
	f[0]=1;
	fore(i,1,n+1){
		f2[0]=1;
		fore(j,1,405){
			f2[j]=0;
			fore(k,0,j+1)f2[j]=add(f2[j],mul(f[k],f[j-k]));
			fore(k,0,j)f2[j]=add(f2[j],mul(f[k],f[j-1-k]));
			fore(k,0,j+1)f2[j]=add(f2[j],mul(2*j,mul(f[k],f[j-k])));
			fore(k,0,j+2)f2[j]=add(f2[j],mul(j*(j+1),mul(f[k],f[j+1-k])));
		}
		memcpy(f,f2,sizeof(f));
	}
	printf("%d\n",f[1]);
	return 0;
}