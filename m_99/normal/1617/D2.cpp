#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int query(int a,int b,int c){
	cout<<"? "<<a+1<<' '<<b+1<<' '<<c+1<<endl;
	int ret;
	cin>>ret;
	return ret;
}

void answer(vector<int> ans){
	cout<<"! "<<ans.size();
	rep(i,ans.size()){
		cout<<' '<<ans[i]+1;
	}
	cout<<endl;
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<int> ans(n,-1);
		vector<int> temp(n/3);
		rep(i,n/3){
			temp[i] = query(i*3,i*3+1,i*3+2);
		}
		int x,y;
		rep(i,temp.size()){
			if(temp[i]!=temp[i+1]){
				int last = temp[i];
				for(int j=i*3+1;true;j++){
					int cur = query(j,j+1,j+2);
					if(last==cur)continue;
					if(cur==0){
						x = j+2;
						y = j-1;
					}
					else{
						x = j-1;
						y = j+2;
					}
					goto L;
					
				}
					
				
				
			}
		}
		L:;
		ans[x] = 0;
		ans[y] = 1;
		rep(i,temp.size()){
			if(i==x/3 || i==y/3){
				for(int j=i*3;j<i*3+3;j++){
					if(ans[j]!=-1)continue;
					ans[j] = query(x,y,j);
				}
			}
			else{
				if(temp[i]==0){
					int t = query(i*3,i*3+1,y);
					if(t==0){
						ans[i*3] = 0;
						ans[i*3+1] = 0;
						ans[i*3+2] = query(i*3+2,x,y);
					}
					else{
						ans[i*3] = query(i*3,x,y);
						ans[i*3+1] = ans[i*3]^1;
						ans[i*3+2] = 0;
					}
				}
				else{
					int t = query(i*3,i*3+1,x);
					if(t==1){
						ans[i*3] = 1;
						ans[i*3+1] = 1;
						ans[i*3+2] = query(i*3+2,x,y);
					}
					else{
						ans[i*3] = query(i*3,x,y);
						ans[i*3+1] = ans[i*3]^1;
						ans[i*3+2] = 1;
					}
				}
			}
		}
		vector<int> p;
		rep(i,n){
			if(ans[i]==0)p.push_back(i);
		}
		answer(p);
		
	}
	
	return 0;
}