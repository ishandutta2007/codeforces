#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//typedef int64_t int;
#define mp make_pair
#define pb push_back
#define a first
#define b second
#define endl "\n"
int it[4001][4001];
int dp[801][4001];
int c[4001][4001];
int n;
int kk;
#define get getchar
int scan() {
    int n=0;
    char c;
    c=get();
    while(c<'0'||c>'9') c=get();
    while(c>='0'&&c<='9') {
        n=n*10+c-'0';
        c=get();
    }
    return n;
}
int dnc(int l,int r,int i,int j,int ind){
	if(l>r){
		return 0;
	}
	//cout<<i<<" "<<j<<","<<l<<" "<<r<<endl;
	int mid=(l+r)/2;
	pair<int,int> best;
	best.a=kk;


	for(int ii=min(mid,j);ii>=max(i,ind);ii--){
	//	cout<<dp[ind-1][ii-1]+c[ii][mid]<<" "<<ii<<endl;
		best=min(best,{dp[ind-1][ii-1]+c[ii][mid],ii});
	}
//	cout<<best.a<<":"<<best.b<<endl;
	dp[ind][mid]=best.a;
	dnc(l,mid-1,i,best.b,ind);
	dnc(mid+1,r,best.b,j,ind);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int k;
	n=scan();
	k=scan();
//	cin>>n>>k;
	kk=10*n*n;
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			dp[i][j]=kk;
		}
	}
	int aa;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			aa=scan();
			//cin>>aa;
			it[i][j]=aa;
			if(j>0){
				it[i][j]+=it[i][j-1];
			}
		}
	}
	for(int i=0;i<n;i++){
		c[0][i]=0;
		if(i>0){
			c[0][i]+=c[0][i-1];
		}
		c[0][i]+=it[i][i];
	}
	for(int i=1;i<n;i++){
		c[i][i]=0;
		for(int j=i+1;j<n;j++){
			c[i][j]=c[i-1][j]-(it[i-1][j]-it[i-1][i-1]);
		}
	}
/*	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;*/
	for(int i=0;i<n;i++){
		dp[0][i]=c[0][i];
	}
	for(int ind3=1;ind3<k;ind3++){
		dnc(0,n-1,0,n-1,ind3);
		/*for(int ij=0;ij<n;ij++){
			cout<<dp[ind3][ij]<<',';
		}
		cout<<endl;*/
	}
	cout<<dp[k-1][n-1]<<endl;
		
	return 0;
}