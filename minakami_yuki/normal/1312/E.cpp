#include<iostream>
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
const int N=1050;
const LL P=998244353;
int n,m;
int f[600][600];
int a[N];
int g[N];
int main(){
	cin>>n;
	for(int i=1;i<=n;++i) {
		scanf("%d",&a[i]);
		f[i][i]=a[i];
	}
	for(int len=2;len<=n;++len){
		for(int l=1,r=len;r<=n;++l,++r){
			for(int k=l;k<r;++k){
				if(f[l][k]&&f[l][k]==f[k+1][r]) {
					f[l][r]=f[l][k]+1;
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;++i) g[i]=n;
	for(int i=0;i<n;++i){
		for(int j=i+1;j<=n;++j){
			if(f[i+1][j]) g[j]=min(g[j],g[i]+1);
		}
	}
	cout<<g[n]<<endl;
	return 0;
}