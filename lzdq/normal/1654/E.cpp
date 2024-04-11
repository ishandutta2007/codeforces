#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<unordered_map>
#include<ctime>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5,B=300,NB=MAXN/B;
int n,a[MAXN],ans;
//unordered_map<ll,int> cnt;
int tot;
ll b[MAXN];
int main(){
	//n=1e5;
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",a+i);
		//a[i]=i;
	}
	ans=1;
	for(int k=-B; k<=B; k++){
		for(int i=1; i<=n; i++)
			b[i]=a[i]-1ll*k*i;
		sort(b+1,b+n+1);
		for(int i=1,j=1; i<=n; i++){
			if(b[i]!=b[j]) j=i;
			ans=max(ans,i-j+1);
		}
			//ans=max(ans,++cnt[a[i]-1ll*k*i]);
	}
	//printf("%.2f\n",(double)(clock())/CLOCKS_PER_SEC);
	for(int i=1; i<=n; i++){
		tot=0;
		for(int j=i+1; j<=i+NB&&j<=n; j++){
			ll t=a[j]-a[i];
			if(t%(j-i)==0) 
				b[++tot]=t/(j-i);
				//ans=max(ans,1+(++cnt[t/(j-i)]));
		}
		sort(b+1,b+tot+1);
		for(int j=1,k=1; j<=tot; j++){
			if(b[j]!=b[k]) k=j;
			ans=max(ans,j-k+2);
		}
	}
	printf("%d\n",n-ans);
	//printf("%.2f\n",(double)(clock())/CLOCKS_PER_SEC);
	return 0;
}