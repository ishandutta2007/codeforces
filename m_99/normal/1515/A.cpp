#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,x;
		cin>>n>>x;
		
		vector<int> w(n);
		rep(i,n){
			scanf("%d",&w[i]);
		}
		
		int sum = 0;
		bool f = true;
		rep(i,n){
			sum += w[i];
			if(sum==x){
				if(i==n-1){
					f=false;
				}
				else{
					swap(w[i],w[i+1]);
					break;
				}
			}
		}
		
		
		if(f){
			cout<<"YES"<<endl;
			rep(i,n){
				if(i!=0)printf(" ");
				printf("%d",w[i]);
			}
			cout<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		
		
		
		
	}
	
    return 0;
}