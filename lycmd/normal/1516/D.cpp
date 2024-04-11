#include<bits/stdc++.h>
using namespace std;
int const N=100010,B=18;
int n,q,a[N],cnt[N],s1[B][N],f[B][N];
int add(int x){
	int t=x;
	for(int i=2;i*i<=x;i++)
		if(x%i==0){
			if(cnt[i])return 0;
			while(x%i==0)x/=i;
		}
	if(x>1&&cnt[x])return 0;
	x=t;
	for(int i=2;i*i<=x;i++)
		if(x%i==0){
			cnt[i]=1;
			while(x%i==0)x/=i;
		}
	if(x>1)cnt[x]=1;
	return 1;
}
void del(int x){
	for(int i=2;i*i<=x;i++)
		if(x%i==0){
			cnt[i]=0;
			while(x%i==0)x/=i;
		}
	if(x>1)cnt[x]=0;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int p=1;
	for(int i=1;i<=n;i++){
		for(;p<=n&&add(a[p]);p++);
		f[0][i]=p-1,del(a[i]);
	}
	for(int i=1;i<B;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=f[i-1][min(f[i-1][j]+1,n)];
	while(q--){
		int l,r,cnt=1;cin>>l>>r;
		for(int i=B-1;~i;i--)
			if(f[i][l]<r)
				l=f[i][l]+1,cnt+=1<<i;
		cout<<cnt<<"\n";
	}
}