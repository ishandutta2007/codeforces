#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=1000010;
int t,n,c,a[N],f[N];
int sum(int l,int r){
	return f[r]-f[l-1];
}
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>c;
		for(int i=1;i<=c;i++)
			f[i]=0;
		for(int i=1;i<=n;i++)
			cin>>a[i],f[a[i]]=1;
		for(int i=1;i<=c;i++)
			f[i]+=f[i-1];
		int flg=1;
		for(int i=1;i<=c;i++){
			if(sum(i,i))continue;
			for(int j=1;j*i<=c;j++)
				if(sum(j,j)&&sum(j*i,min(j*i+j-1,c))){
					flg=0;
					goto finish;
				}
		}
finish:	cout<<(flg?"Yes\n":"No\n");
	}
}