#include<bits/stdc++.h>
using namespace std;
int const N=2333;
int n,m,k,ans[N][N];
char a[N][N],b[N][N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++)
			cin>>a[i][j],a[i][j]=a[i][j]=='E';
		if(i<n)
			for(int j=1;j<=m;j++)
				cin>>b[i][j],b[i][j]=b[i][j]=='E';
	}
	if(k==1){
		int cnt=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				if(i<n)cnt+=b[i][j];
				if(j<m)cnt+=a[i][j];
			}
		if(cnt*4<(2*n*m-n-m)*3)
	 		cout<<"NO\n";
		else{
			cout<<"YES\n";
			for(int i=1;i<=n;i++,cout<<"\n")
				for(int j=1;j<=m;j++)
					cout<<"1 ";
		}
		return 0;
	}
	ans[1][1]=1;
	if(n>=m){
		for(int i=1;i<n;i++)
			ans[i+1][1]=b[i][1]?ans[i][1]:3-ans[i][1];
		for(int i=1;i<=n;i+=2)
			for(int j=1;j<m;j++)
				ans[i][j+1]=a[i][j]?ans[i][j]:3-ans[i][j];
		for(int i=2;i<=n;i+=2)
			for(int j=2;j<=m;j++)
				ans[i][j]=2-(((ans[i][j-1]>1)^a[i][j-1])
					+((ans[i-1][j]>1)^b[i-1][j])+((ans[i+1][j]>1)^b[i][j])>1);
	}else{
		for(int i=1;i<m;i++)
			ans[1][i+1]=a[1][i]?ans[1][i]:3-ans[1][i];
		for(int j=1;j<=m;j+=2)
			for(int i=1;i<n;i++)
				ans[i+1][j]=b[i][j]?ans[i][j]:3-ans[i][j];
		for(int j=2;j<=m;j+=2)
			for(int i=2;i<=n;i++)
				ans[i][j]=2-(((ans[i][j-1]>1)^a[i][j-1])
					+((ans[i-1][j]>1)^b[i-1][j])+((ans[i][j+1]>1)^a[i][j])>1);
	}
	cout<<"YES\n";
	for(int i=1;i<=n;i++,cout<<"\n")
		for(int j=1;j<=m;j++)
			cout<<ans[i][j]<<" ";
}