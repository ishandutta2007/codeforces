#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



int main(){
	
	int _t;
	cin>>_t;
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		
		vector<string> S(n);
		
		rep(i,n){
			cin>>S[i];
		}
		
		vector<int> cnt(3,0);
		
		rep(i,n){
			rep(j,n){
				if(S[i][j]=='X'){
					cnt[(i+j)%3]++;
				}
			}
		}
		
		int mini = Inf,c = 0;
		rep(i,3){
			if(mini>cnt[i]){
				mini = cnt[i];
				c = i;
			}
		}
		
		rep(i,n){
			rep(j,n){
				if(S[i][j]=='X'&&(i+j)%3==c){
					S[i][j] = 'O';
				}
			}
		}
		
		rep(i,n){
			cout<<S[i]<<endl;
		}
		
	}
	
    return 0;
}