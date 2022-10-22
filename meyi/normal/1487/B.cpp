#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=110;
int k,n,t;
inline int qwq(int n,int k){
	int apos=1,bpos=n;
	while(k--){
		++apos,--bpos;
		if(apos>n)apos=1;
		if(bpos<1)bpos=n;
		if(apos==bpos)++apos;
		if(apos>n)apos=1;
	}
	return apos;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		if(n&1){
			k%=1ll*n*(n>>1);
			if(!k)k=1ll*n*(n>>1);
			--k;
			if(!k)k=1ll*n*(n>>1);
			k+=k/(n>>1);
		}
		else --k;
		printf("%d\n",(k%n)+1);
	}
	return 0;
}