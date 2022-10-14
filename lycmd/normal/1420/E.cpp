#include<bits/stdc++.h>
using namespace std;
int const N=85,M=3205;
int n,ans,a[N],f[N][N][M];
vector<int>p;
void tomax(int&x,int y){
	if(x<y)x=y;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i])p.push_back(i);
	}
	memset(f,0xcc,sizeof f),f[0][0][0]=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<=min(i,(int)p.size()-1);j++)
			for(int k=0;k<M;k++)
				if(f[i][j][k]>=0)
					for(int t=i+1;t<=n;t++)
						tomax(f[t][j+1][k+abs(t-p[j])],f[i][j][k]+(i-j)*(t-i-1));
	for(int i=0;i<=n*(n-1)/2;i++){
		for(int j=1;j<=n;j++)
			tomax(ans,f[j][p.size()][i]+(j-p.size())*(n-j));
		cout<<ans<<" ";
	}
	cout<<"\n";
}