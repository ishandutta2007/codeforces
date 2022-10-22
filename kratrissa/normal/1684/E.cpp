#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int read(){
	int res=0;char c=getchar();
	while(c<48)c=getchar();
	while(c>=48)res=res*10+c-48,c=getchar();
	return res;
}
int T,n,k,kk,a[N],q[N],m;map<int,int> cnt;
void solve(){
	n=read(),kk=k=read(),cnt.clear();
	for(int i=1;i<=n;i++)a[i]=read(),cnt[a[i]]++;
	int mex=0;
	for(;mex<n;mex++){if(cnt[mex]==0)k--;if(k<0)break;}
	m=0;
	for(auto qwq:cnt)if(qwq.first>mex)q[++m]=qwq.second;
	sort(q+1,q+m+1);
	int awa=1;
	while(kk>=q[awa]&&awa<=m)kk-=q[awa],awa++;
	printf("%d\n",m-awa+1);
}
int main(){
	T=read();
	while(T--)solve();
	return 0;
}