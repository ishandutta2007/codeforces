#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
double comb(int nn,int mm){
	double ret=1.0;
	for(int i=1;i<=mm;i++){
		ret=ret*(nn-mm+i);
		ret=ret/i;
	}
	return ret;
}
signed main(){
	cin>>n>>m>>k;
	if(n+k<m){
		puts("0");
		return 0;
	}
	if(k>=m){
		puts("1");
		return 0;
	}
	double ans=1;
	for(int i=0;i<=k;i++)ans*=(double)(m-i)/(n+i+1);
	cout<<1.0-ans<<endl;
	return 0;
}