#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int query(int x0,int y0,int x1,int y1){
	if(x0+y0>x1+y1){
		swap(x0,x1);
		swap(y1,y0);
	}
	cout<<"? "<<x0+1<<' '<<y0+1<<' '<<x1+1<<' '<<y1+1<<endl;
	int ret;
	cin>>ret;
	return ret;
}

int main(){
	
	int n;
	cin>>n;
	
	vector ans(n,vector<int>(n,-1));
	ans[0][0] = 1;
	ans.back().back() = 0;
	ans[0][1] = 2;
	
	vector dx = {2,0,1,-2,0,-1},dy = {0,2,1,0,-2,-1};
	
	rep(i,n){
		rep(j,n){
			if(ans[i][j]==-1)continue;
			rep(k,dx.size()){
				int yy = i+dy[k],xx = j+dx[k];
				if(yy<0||yy>=n||xx<0||xx>=n)continue;
				if(ans[yy][xx]!=-1)continue;
				if(query(i,j,yy,xx))ans[yy][xx] = ans[i][j];
				else ans[yy][xx] = ans[i][j]^1;
			}
		}
	}
	
	vector<vector<int>> ddx = {{1,2,2},{1,1,1},{0,0,1},{0,1,2},{-1,-2,-2},{-1,-1,-1},{0,0,-1},{0,-1,-2}},
	ddy = {{0,0,1},{0,1,2},{1,2,2},{1,1,1},{0,0,-1},{0,-1,-2},{-1,-2,-2},{-1,-1,-1}};
	
	int mask = 0;
	rep(i,n){
		rep(j,n){
			if((i+j)%2==0)continue;
			rep(k,8){
				int yy = i + ddy[k].back(),xx = j+ddx[k].back();
				if(yy>=n||xx>=n||yy<0||xx<0)continue;
				if((ans[i][j]^ans[yy][xx])!=(ans[i+ddy[k][0]][j+ddx[k][0]]^ans[i+ddy[k][1]][j+ddx[k][1]]))continue;
				int ret = query(i,j,yy,xx);
				if(ret){
					ret = ans[yy][xx];
				}
				else{
					ret = ans[yy][xx]^1;
				}
				if(ret == (ans[i][j]&1))mask = 2;
				else mask = 3;
				goto OK;
			}
		}
	}
	
	OK:;
	
	rep(i,n){
		rep(j,n){
			if(ans[i][j]>=2)ans[i][j] ^= mask;
		}
	}
	cout<<"!"<<endl;
	rep(i,n){
		rep(j,n){
			cout<<ans[i][j];
		}
		cout<<endl;
	}
	
    return 0;
}