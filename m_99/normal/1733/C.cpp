#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001

void Do(vector<int> &a,vector<int> &x,vector<int> &y,int l,int r){
	if((a[l]+a[r])%2==1){
		a[r] = a[l];
	}
	else a[l] = a[r];
	x.push_back(l+1);
	y.push_back(r+1);
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<int> a(n);
		rep(i,n){
			cin>>a[i];
		}
		vector<int> x,y;
		if(a[0]%2==a[n-1]%2 && a[0]!=a[n-1]){
			Do(a,x,y,0,n-1);
		}
		
		rep(i,n){
			if(a[0]%2!=a[i]%2){
				Do(a,x,y,0,i);
			}
		}
		rep(i,n){
			if(a[i]!=a[n-1]){
				Do(a,x,y,i,n-1);
			}
		}
		
		cout<<x.size()<<endl;
		rep(i,x.size()){
			printf("%d %d\n",x[i],y[i]);
		}
	}
	
	return 0;
}