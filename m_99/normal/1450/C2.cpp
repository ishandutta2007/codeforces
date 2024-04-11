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
		
		vector<int> cntXO(3,0),cntOX(3,0);
		
		rep(i,n){
			rep(j,n){
				if(S[i][j]=='X'){
					cntXO[(i+j)%3]++;
				}
				if(S[i][j]=='O'){
					cntOX[(i+j)%3]++;
				}
			}
		}
		
		int m = Inf,ii=0,jj=0;
		
		rep(i,3){
			rep(j,3){
				if(i==j)continue;
				int temp = cntXO[i]+cntOX[j];
				if(temp<m){
					m = temp;
					ii = i;
					jj = j;
				}
			}
		}
		
		rep(i,n){
			rep(j,n){
				if((i+j)%3==ii){
					if(S[i][j]=='X')S[i][j]='O';
				}
				if((i+j)%3==jj){
					if(S[i][j]=='O')S[i][j]='X';
				}
			}
		}
		
		rep(i,n){
			cout<<S[i]<<endl;
		}
		
	}
	
    return 0;
}