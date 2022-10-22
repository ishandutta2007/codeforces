#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 100000000


int main(){	
	
	int t;
	cin>>t;
	rep(_,t){
		int n;
		cin>>n;
		vector<int> a(n);
		int m,M;
		rep(i,n){
			scanf("%d",&a[i]);
			if(i==0){
				m=a[i],M=a[i];
			}
			else{
				m=min(m,a[i]);
				M=max(M,a[i]);
			}
		}
		
		if(m==M){
			cout<<-1<<endl;
			continue;
		}
		rep(i,n){
			if(i!=0&&a[i]==M&&a[i-1]!=M){
				cout<<i+1<<endl;
				break;
			}
			if(a[i]==M&&a[i+1]!=M){
				cout<<i+1<<endl;
				break;
			}
		}
		
	}
		
    return 0;
}