#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=100;
char a[N][N];
bool c1[N],c2[N];

int work(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]=='P')goto no0;
		}
	}
	return 0;
	no0:;
	memset(c1,false,sizeof(c1));
	memset(c2,false,sizeof(c2));
	for(int i=0;i<n;i++){
		c1[i]=true;
		for(int j=0;j<m;j++){
			if(a[i][j]=='P')c1[i]=false;
		}
	}
	for(int i=0;i<m;i++){
		c2[i]=true;
		for(int j=0;j<n;j++){
			if(a[j][i]=='P')c2[i]=false;
		}
	}
	if(c1[0]||c1[n-1]||c2[0]||c2[m-1])return 1;
	for(int i=0;i<n;i++)if(c1[i])return 2;
	for(int i=0;i<m;i++)if(c2[i])return 2;
	if(a[0][0]=='A'||a[0][m-1]=='A'||a[n-1][0]=='A'||a[n-1][m-1]=='A')return 2;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]=='A'&&(i==0||i==n-1||j==0||j==m-1))return 3;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]=='A')return 4;
		}
	}
	return 5;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int ans=work();
		if(ans==5){
			puts("MORTAL");
		}
		else{
			printf("%d\n",ans);
		}
	}
	return 0;
}