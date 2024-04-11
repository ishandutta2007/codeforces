//
//  
//
//
//  
//  
//   
//
//
#include<bits/stdc++.h>
using namespace std;
const string A="What are you doing at the end of the world? Are you busy? Will you save us?";
const string Z1="What are you doing while sending \"",Z2="\"? Are you busy? Will you send \"",Z3="\"?";
const int deta=Z1.size()+Z2.size()+Z3.size();long long f[100005],k;int Q,n;
inline char dfs(int n,long long k)
{
	if(k>f[n]) return '.';else if(n==0) return A[k];
	if(k<(int)Z1.size()) return Z1[k];else k-=Z1.size();
	if(k<f[n-1]) return dfs(n-1,k);else k-=f[n-1];
	if(k<(int)Z2.size()) return Z2[k];else k-=Z2.size();
	if(k<f[n-1]) return dfs(n-1,k);else k-=f[n-1];
	if(k<(int)Z3.size()) return Z3[k];else k-=Z3.size();
	return '.';
}
int main()
{
	memset(f,0x3f,sizeof(f)),f[0]=A.size();for(int i=1;i<=55;i++) f[i]=(f[i-1]<<1)+deta;
	for(scanf("%d",&Q);Q--;) scanf("%d%lld",&n,&k),k--,putchar(dfs(n,k));
	return 0;
}