#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#if (!defined(__cplusplus) || __cplusplus > 201103)
/**
 * Use scanner in c++14, c++17 or c++20!
 */
template<class T>
struct Scanner{
	int value;
	Scanner(){
		value=0;
		int ch;
		while(isdigit(ch=getchar())){
			value=value*10+(ch^'0');
		}
	}
};
Scanner<int> qaq;
#else
#endif
const int N=200200;
char s[N];
int f[N];
int n,k;
LL dp[N];
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	f[n+1]=n+n+n;
	for(int i=n;i>=1;i--){
		f[i]=s[i]=='1'?i:f[i+1];
	}
	dp[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]+i;
		int c=f[max(i-k,1)];
		if(c<=i+k){
			dp[i]=min(dp[i],dp[max(1,c-k)-1]+c);
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}