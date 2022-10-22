#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m;
		cin>>n>>m;
		
		vector<int> t;
		rep(i,n){
			rep(j,m){
				int c = 0;
				c = max(c,i+j);
				c = max(c,i+(m-1-j));
				c = max(c,(n-1-i)+j);
				c = max(c,(n-1-i)+(m-1-j));
				t.push_back(c);
			}
		}
		sort(t.begin(),t.end());
		rep(i,t.size()){
			if(i!=0)printf(" ");
			printf("%d",t[i]);
		}
		cout<<endl;
		
	}
	
	return 0;
}