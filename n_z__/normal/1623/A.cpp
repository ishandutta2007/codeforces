#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,rb,cb,rd,cd,dc=1,dr=1,cnt=0;
		cin>>n>>m>>rb>>cb>>rd>>cd;
		while(rb!=rd&&cb!=cd){
			int nr=dr+rb,nc=dc+cb;
			if(nr<=0||nr>n){
				dr=-dr;
			}
			if(nc<=0||nc>m){
				dc=-dc;
			}
			rb=dr+rb,cb=dc+cb;
			cnt++;
		}
		cout<<cnt<<endl;
	} 
}