#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define MOD 1000000007
using namespace std;
typedef long long ll;

bool b[5005];
int f[5005];
int n;

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		char s[4];
		scanf("%s",s);
		b[i]=s[0]=='f';
	}
	f[0]=1;
	for(int i=n-1;i>=0;--i){
		if(b[i])fore(i,0,n+1)f[i]=f[i+1];
		else fore(i,1,n+1)f[i]+=f[i-1],f[i]%=MOD;
	}
	printf("%d\n",f[0]);
	return 0;
}