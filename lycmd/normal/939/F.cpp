#include<bits/stdc++.h>
using namespace std;
int const N=200010,M=105,INF=0x3f3f3f3f;
int n,m,k,ql[N],qr[N],f[M][N],q[N];
void tomin(int&x,int y){
	if(x>y)x=y;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=k;i++)
		cin>>ql[i]>>qr[i];
	memset(f,0x3f,sizeof f),f[0][0]=0;
	for(int i=1;i<=k;i++){
		memcpy(f[i],f[i-1],sizeof f[i]);
		int l=1,r=0;
		for(int j=0;j<=qr[i];j++){
			while(l<=r&&q[l]<j-qr[i]+ql[i])l++;
			while(l<=r&&f[i-1][q[r]]>=f[i-1][j])r--;
			q[++r]=j;
			tomin(f[i][j],f[i-1][q[l]]+2);
		}
		l=1,r=0;
		for(int j=qr[i];j>=0;j--){
			while(l<=r&&q[l]<ql[i]-j)l++;
			while(l<=r&&f[i-1][q[r]]>=f[i-1][qr[i]-j])r--;
			q[++r]=qr[i]-j;
			tomin(f[i][j],f[i-1][q[l]]+1);
		}
	}
	if(f[k][n]<INF)
		cout<<"Full\n"<<f[k][n]<<"\n";
	else
		cout<<"Hungry\n";
}