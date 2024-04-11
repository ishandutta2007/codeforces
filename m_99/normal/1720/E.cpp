#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
#define InfL 4000000000000000001



int main() {	
	
	int n;
	cin>>n;
	
	int k;
	cin>>k;
	
	set<int> s;
	
	vector a(n,vector<int>(n));
	vector<int> cnt(n*n,0);
	rep(i,n){
		rep(j,n){
			scanf("%d",&a[i][j]);
			a[i][j]--;
			cnt[a[i][j]]++;
		}
	}
	int sum = 0;
	rep(i,n*n){
		if(cnt[i]>0)sum++;
	}
	
	if(k>sum){
		cout<<k-sum<<endl;
		return 0;
	}
	
	if(k==sum){
		cout<<0<<endl;
		return 0;
	}
	rep(_,2){
		rep(i,n){
			int x = 0,y = i;
			if(_==1)swap(x,y);
			vector<int> cs(n*n,0);
			int csum = sum;
			int t = 0;
			while(true){
				while(k < csum){
					int xx = x + t,yy = y + t;
					if(xx>=n||yy>=n)break;
					rep(j,t+1){
						cs[a[xx][y+j]]++;
						if(cs[a[xx][y+j]]==cnt[a[xx][y+j]])csum--;
					}
					rep(j,t){
						cs[a[x+j][yy]]++;
						if(cs[a[x+j][yy]]==cnt[a[x+j][yy]])csum--;
					}
					t++;
					if(k==csum || k==csum+1){
						cout<<1<<endl;
						return 0;
					}
				}
				if(k==csum || k==csum+1){
					cout<<1<<endl;
					return 0;
				}
				int xx = x + t,yy = y + t;
				if(xx>=n||yy>=n)break;
				rep(j,t+1){
					if(cs[a[xx-j][y]]==cnt[a[xx-j][y]])csum++;
					cs[a[xx-j][y]]--;
				}
				rep(j,t){
					if(cs[a[x][yy-j]]==cnt[a[x][yy-j]])csum++;
					cs[a[x][yy-j]]--;
				}
				
				if(k==csum || k==csum+1){
					cout<<1<<endl;
					return 0;
				}
				x++,y++;
				t--;
				if(x>=n||y>=n)break;
			}
			
		}
	}
	
	cout<<2<<endl;
	
	
    return 0;
}