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
		vector<string> s(n);
		rep(i,n)cin>>s[i];
		if(s[0][0]=='1'){
			cout<<-1<<endl;
			continue;
		}
		vector<int> a,b,c,d;
		
		for(int i=n-1;i>=0;i--){
			for(int j=m-1;j>=0;j--){
				if(s[i][j]=='1'){
					if(i!=0){
						a.push_back(i-1);
						b.push_back(j);
						c.push_back(i);
						d.push_back(j);
					}
					else{
						a.push_back(i);
						b.push_back(j-1);
						c.push_back(i);
						d.push_back(j);
					}
				}
			}
		}
		cout<<a.size()<<endl;
		rep(i,a.size()){
			printf("%d %d %d %d\n",a[i]+1,b[i]+1,c[i]+1,d[i]+1);
		}
		
	}
	
	return 0;
}