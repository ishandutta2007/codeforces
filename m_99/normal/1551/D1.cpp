#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m,k;
		scanf("%d %d %d",&n,&m,&k);
		vector<string> ans(n,string(m,'.'));
		if(m%2==0){
			
			if(n%2==1){
				if(m/2>k){
					cout<<"NO"<<endl;
					continue;
				}
				rep(j,m)ans.back()[j] = 'o';
				k -= m/2;
				n--;
				
			}
			
			int y = 0,x = 0;
			rep(i,k){
				int y = i%n,x = i/n*2;
				ans[y][x] = 'o';
				ans[y][x+1] = 'o';
				y++;
			}
			
			for(int i=n-1;i>=1;i--){
				rep(j,m){
					if(ans[i][j]=='.'&&ans[i-1][j]=='.'){
						ans[i][j] = 'x';
						ans[i-1][j] = 'x';
					}
				}
			}
			
		}
		else{
			k = (n*m)/2 - k;
			if(m%2==1){
				if(n/2>k){
					cout<<"NO"<<endl;
					continue;
				}
				k -= n/2;
				rep(j,n){
					ans[j].back() = 'x';
				}
				
				m--;
			}
			rep(i,k){
				int y = i/m * 2;
				int x = i%m;
				ans[y][x] = 'x';
				ans[y+1][x] = 'x';
			}
			for(int i=m-1;i>=1;i--){
				rep(j,n){
					if(ans[j][i]=='.'&&ans[j][i-1]=='.'){
						ans[j][i] = 'o';
						ans[j][i-1] = 'o';
					}
				}
			}
		}
		bool f = true;
		n = ans.size(),m = ans[0].size();
		rep(i,n){
			rep(j,m){
				if(ans[i][j]=='.'){
					f = false;
				}
			}
		}
		if(!f){
			printf("NO\n");
		}
		else{
			printf("YES\n");
			
			
			
		}
				
	
		
	}
	
	return 0;
}