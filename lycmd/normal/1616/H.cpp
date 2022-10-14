#include<bits/stdc++.h>
#define int long long
#define ls(x) (tr[x][0])
#define rs(x) (tr[x][1]) 
using namespace std;
int const N=5000010,MOD=998244353;
int n,k,x,tot=1,pw[N],cnt[N],tr[N][2];
int newnode(){
	return tot++,cnt[tot]=tr[tot][0]=tr[tot][1]=0,tot;
}
void insert(int x){
	cnt[1]++;
	for(int p=1,i=30;~i;i--){
		int&t=tr[p][x>>i&1];
		if(!t)t=newnode();
		cnt[p=t]++;
	}
}
int solve(int x,int y,int d){
	return  
		!x?pw[cnt[y]]:
		!y?pw[cnt[x]]:
		d<0?pw[cnt[x]+(x!=y)*cnt[y]]:
		k>>d&1?
			x^y?solve(ls(x),rs(y),d-1)*solve(rs(x),ls(y),d-1)%MOD:
			solve(ls(x),rs(x),d-1):
		x^y?(solve(ls(x),ls(y),d-1)+solve(rs(x),rs(y),d-1)-1+
			(pw[cnt[ls(x)]]-1)*(pw[cnt[rs(x)]]-1)%MOD+
			(pw[cnt[ls(y)]]-1)*(pw[cnt[rs(y)]]-1)%MOD+MOD)%MOD:
		(solve(ls(x),ls(x),d-1)+solve(rs(x),rs(x),d-1)-1+MOD)%MOD;
}
signed main(){
	ios::sync_with_stdio(0);
	for(int i=0;i<N;i++)
		pw[i]=i?pw[i-1]*2%MOD:1;
	for(cin>>n>>k;n--;)
		cin>>x,insert(x);
	cout<<(solve(1,1,30)-1+MOD)%MOD<<"\n";
}