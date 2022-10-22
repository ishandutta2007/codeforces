#include<cstdio>
#include<cstring>
const int MAXN=1e5+5,Mod=1e9+7;
int n,f[MAXN];
char s[MAXN];
int Calc(){
	int sum=0,res=1;
	for(int i=1;s[i];i++){
		if(i<=2) f[i]=i;
		else f[i]=(f[i-2]+f[i-1])%Mod;
		if(s[i]=='w'||s[i]=='m') return 0;
		if(s[i]=='n'){
			if(!sum||s[i-1]=='n') sum++;
			else res=1ll*res*f[sum]%Mod,sum=1;
		}else if(s[i]=='u'){
			if(!sum||s[i-1]=='u') sum++;
			else res=1ll*res*f[sum]%Mod,sum=1;
		}else if(sum) res=1ll*res*f[sum]%Mod,sum=0;
	}
	if(sum) res=1ll*res*f[sum]%Mod;
	return res;
}
//	1 2 3 4 5
//	1 2 3 5
int main(){
	scanf("%s",s+1);
	printf("%d\n",Calc());
	return 0;
}