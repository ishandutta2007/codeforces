#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<iomanip>
#include<tuple>
#include<cassert>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(vector<int> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%d%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%lld%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}

void init(){
	
}

int n,m;
int t[55][55];
string sa[55];

void check(int x,int y){
	if(x<0 || x>=n || y<0 || y>=m)return;
	if(t[x][y]!=-1)return;
	t[x][y]=1;
	check(x+1,y);
	check(x-1,y);
	check(x,y+1);
	check(x,y-1);
}

void put(int x,int y){
	if(x<0 || x>=n || y<0 || y>=m)return;
	if(sa[x][y]=='.')sa[x][y]='#';
}

bool solve(){
	int i,j,k;
	int a,b,c;
	cin>>n>>m;
	memset(t,-1,sizeof(t));
	for(i=0;i<n;i++){
		cin>>sa[i];
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(sa[i][j]=='B'){
				put(i+1,j);
				put(i-1,j);
				put(i,j+1);
				put(i,j-1);
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(sa[i][j]=='#')t[i][j]=-2;
		}
	}
	check(n-1,m-1);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(sa[i][j]=='B' && t[i][j]==1)return false;
			if(sa[i][j]=='G' && t[i][j]!=1)return false;
		}
	}
	return true;
}

int main(){
	int n,i;
	init();
	cin>>n;
	for(i=0;i<n;i++){
		if(solve())cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}