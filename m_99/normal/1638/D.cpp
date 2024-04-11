#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000000

int n,m;
vector<vector<int>> a;

bool check(int x,int y){
	if(x<0||y<0||x>=n-1||y>=m-1)return false;
	int last = -1;
	rep(i,2){
		rep(j,2){
			if(a[i+x][j+y]!=-1){
				if(last==-1)last = a[i+x][j+y];
				else if(last!=a[i+x][j+y])return false;
			}
		}
	}
	if(last==-1)return false;
	return true;
}

int main(){
	
	cin>>n>>m;
	a.resize(n,vector<int>(m));
	rep(i,n){
		rep(j,m){
			scanf("%d",&a[i][j]);
		}
	}
	set<pair<int,int>> S;
	rep(i,n){
		rep(j,m){
			if(check(i,j))S.emplace(i,j);
		}
	}
	
	vector<int> X,Y,C;
	
	while(S.size()!=0){
		int x = (*S.begin()).first;
		int y = (*S.begin()).second;
		S.erase(S.begin());
		X.push_back(x);
		Y.push_back(y);
		rep(i,2){
			rep(j,2){
				if(a[i+x][j+y]!=-1 && X.size()!=C.size())C.push_back(a[i+x][j+y]);
				a[i+x][j+y] = -1;
			}
		}
		
		if(X.size()!=C.size()){
			X.pop_back();
			Y.pop_back();
			continue;
		}
		
		for(int i=-1;i<=1;i++){
			for(int j=-1;j<=1;j++){
				if(check(x+i,y+j))S.emplace(x+i,y+j);
			}
		}
	}
	
	if(a != vector<vector<int>>(n,vector<int>(m,-1)))cout<<-1<<endl;
	else{
		printf("%d\n",X.size());
		reverse(X.begin(),X.end());
		reverse(Y.begin(),Y.end());
		reverse(C.begin(),C.end());
		rep(i,X.size()){
			printf("%d %d %d\n",X[i]+1,Y[i]+1,C[i]);
		}
	}
	
	return 0;
}