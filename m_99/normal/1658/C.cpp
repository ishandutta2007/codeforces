#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		vector<int> c(n);
		rep(i,n)scanf("%d",&c[i]);
		int pos = -1;
		rep(i,n){
			if(c[i]==1){
				pos = i;
				break;
			}
		}
		if(pos==-1){
			cout<<"NO"<<endl;
			continue;
		}
		bool f = true;
		for(int i=1;i<n;i++){
			int x = pos+i-1;
			int y = pos+i;
			x %= n;
			y %= n;
			
			if(c[y]==1){
				f = false;
			}
			if(c[y]>c[x]+1){
				f = false;
			}
			
		}
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	
	return 0;
}