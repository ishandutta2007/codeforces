#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int T,n,f[N];queue<int> q;
int main(){
	f[0]=0;fill(f+1,f+32768,114514);q.push(0);
	while(!q.empty()){
		int x=q.front();q.pop();
		if(f[(x+32767)&32767]==114514)f[(x+32767)&32767]=f[x]+1,q.push((x+32767)&32767);
		if(x&1)continue;
		if(f[x>>1]==114514)f[x>>1]=f[x]+1,q.push(x>>1);
		if(f[(x>>1)|16384]==114514)f[(x>>1)|16384]=f[x]+1,q.push((x>>1)|16384);
	}
	scanf("%d",&T);
	while(T--)scanf("%d",&n),printf("%d ",f[n]);printf("\n");
	return 0;
}