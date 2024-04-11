//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
int n;
int ask(int i){
	cout<<"? "<<i+1<<endl;
	int x;
	cin>>x;
	return x;
}
void ans(int i){
	cout<<"! "<<i+1<<endl;
}
void solve(int l,int r){
	if(r-l+1<=5){
		for(int i=l;i<=r;i++){
			int x=ask(i);
			int st=1;
			if(i>0){
				if(ask(i-1)<x){
					st=0;
				}
			}
			if(i<n-1){
				if(ask(i+1)<x){
					st=0;
				}
			}
			if(st==1){
				ans(i);
				return;
			}
		}
	}
	else{
		int mid=(l+r)/2;
		int x=ask(mid);
		int y=ask(mid-1);
		if(y<x){
			solve(l,mid);
		}
		else{
			solve(mid-1,r);
		}

	}



}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	if(n==1){
		cout<<"! "<<1<<endl;
	}
	else{
		solve(0,n-1);
	}










 
	return 0;
}