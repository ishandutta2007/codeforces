#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2020;
char s[N][N]={'\0'};
int rcnt[N][N]={0};
int dcnt[N][N]={0};
int rdp[N][N]={0};
int ddp[N][N]={0};
const int MOD=1e9+7;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
	}
	if(n==1&&m==1){
		printf("1\n");
		exit(0);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			rcnt[i][j]=dcnt[i][j]=s[i][j]=='.'?1:0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			rcnt[i][j]+=rcnt[i][j+1];
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++){
			dcnt[i][j]+=dcnt[i+1][j];
		}
	}	
	for(int i=n;i>=1;i--){
		for(int j=m;j>=1;j--){
			if(i==n&&j==m){
				// cerr<<"C"<<endl;
				rdp[i][j]=ddp[i][j]=1;
			}
			else{
				ddp[i][j]=ddp[i+1][j];
				ddp[i][j]+=(rdp[i][j+1]-rdp[i][j+1+rcnt[i][j+1]]+MOD)%MOD;
				ddp[i][j]%=MOD;
				rdp[i][j]=rdp[i][j+1];
				rdp[i][j]+=(ddp[i+1][j]-ddp[i+1+dcnt[i+1][j]][j]+MOD)%MOD;
				rdp[i][j]%=MOD;
			}
		}
	}
	printf("%d\n",((rdp[1][1]-rdp[1][2]+MOD)%MOD+(ddp[1][1]-ddp[2][1]+MOD)%MOD)%MOD);
	return 0;
}