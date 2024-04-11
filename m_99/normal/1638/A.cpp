#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000000


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		vector<int> p(n);
		int ind = 0;
		rep(i,n){
			scanf("%d",&p[i]);
		}
		
		rep(i,n){
			if(p[i]!=i+1){
				ind = i+1;
				break;
			}
		}
		if(ind!=0){
		int l = ind-1;
		rep(i,n){
			if(p[i]==ind){
				ind = i;
				break;
			}
		}
		//cout<<l<<endl;
		reverse(p.begin()+l,p.begin()+ind+1);
		}
		rep(i,n){
			if(i!=0)printf(" ");
			printf("%d",p[i]);
		}
		cout<<endl;
	}
	
	return 0;
}