#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int pm(int a, int e, int mod){
	int r=1;
	while(e){
		if(e&1)r=(1LL*r*a)%mod;
		e>>=1;
		a=(1LL*a*a)%mod;
	}
	return r;
}

int inv(int a, int mod){
	return pm(a,mod-2,mod);
}

bool isp[100005];

int main(){
	memset(isp,true,sizeof(isp));
	for(int i=2;i<100005;++i){
		if(isp[i])for(int j=i+i;j<100005;j+=i)isp[j]=false;
	}
	int n;
	scanf("%d",&n);
	if(n==1)puts("YES\n1");
	else if(n==4)puts("YES\n1\n3\n2\n4");
	else if(!isp[n])puts("NO");
	else {
		puts("YES\n1");
		fore(i,2,n)printf("%d\n",(int)((1LL*i*inv(i-1,n))%n));
		printf("%d\n",n);
	}
	return 0;
}