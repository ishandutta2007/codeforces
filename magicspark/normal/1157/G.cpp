#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,m;
int a[222][222],b[222][222],row[222],col[222];
void check(int x){
	memcpy(b,a,sizeof a);
	memset(row,0,sizeof row);
	memset(col,0,sizeof col);
	for(int i=0;i<m;i++)if(a[0][i])col[i]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<m;j++)if(col[j])b[i][j]^=1;
		if(i==x){
			bool ans=false,tmp=true;
			for(int j=1;j<m;j++)if(b[i][j]<b[i][j-1])tmp=false;
			if(tmp)row[i]=0,ans=true;
			tmp=true;
			for(int j=1;j<m;j++)if(b[i][j]>b[i][j-1])tmp=false;
			if(tmp)row[i]=1,ans=true;
			if(!ans)return;		
		}else{
			if(*max_element(b[i],b[i]+m)!=*min_element(b[i],b[i]+m))return;
			if(i<x){
				if(b[i][0]==1)row[i]=1;
				else row[i]=0;
			}else{
				if(b[i][0]==0)row[i]=1;
				else row[i]=0;
			}
		}
	}
	puts("YES");
	for(int i=0;i<n;i++)putchar(row[i]==0?'0':'1');
	putchar('\n');
	for(int i=0;i<m;i++)putchar(col[i]==0?'0':'1');
	exit(0);
}
void check1(){
	memcpy(b,a,sizeof a);
	memset(row,0,sizeof row);
	memset(col,0,sizeof col);
	for(int i=0;i<m;i++)if(a[n-1][i]==0)col[i]=1;
	int x=0;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m;j++)if(col[j])b[i][j]^=1;
		if(i==x){
			bool ans=false,tmp=true;
			for(int j=1;j<m;j++)if(b[i][j]<b[i][j-1])tmp=false;
			if(tmp)row[i]=0,ans=true;
			tmp=true;
			for(int j=1;j<m;j++)if(b[i][j]>b[i][j-1])tmp=false;
			if(tmp)row[i]=1,ans=true;
			if(!ans)return;
		}else{
			if(*max_element(b[i],b[i]+m)!=*min_element(b[i],b[i]+m))return;
			if(i<x){
				if(b[i][0]==1)row[i]=1;
				else row[i]=0;
			}else{
				if(b[i][0]==0)row[i]=1;
				else row[i]=0;
			}
		}
	}
	puts("YES");
	for(int i=0;i<n;i++)putchar(row[i]==0?'0':'1');
	putchar('\n');
	for(int i=0;i<m;i++)putchar(col[i]==0?'0':'1');
	exit(0);
} 
int main(){
	cin>>n>>m;
	for(int i=0;i<n;++i)for(int j=0;j<m;j++)cin>>a[i][j];
	for(int i=1;i<n;i++){
		check(i);
	}
	check1();
	puts("NO");
	return 0;
}