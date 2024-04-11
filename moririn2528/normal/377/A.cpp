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

int n,m,q;
bool used[1000][1000];
vector<P> v1;

void check(int x,int y){
	if(x<0 || x>=n || y<0 || y>=m)return;
	if(used[x][y])return;
	used[x][y]=true;
	check(x+1,y);
	check(x-1,y);
	check(x,y+1);
	check(x,y-1);
	v1.push_back(make_pair(x,y));
}

int main(){
	int i,j,k;
	int a,b,c;
	cin>>n>>m>>q;
	string sa[1100];
	for(i=0;i<n;i++){
		cin>>sa[i];
		for(j=0;j<m;j++){
			if(sa[i][j]=='#')used[i][j]=true;
			else a=i,b=j;
		}
	}
	check(a,b);
	for(i=0;i<q;i++){
		a=v1[i].first,b=v1[i].second;
		sa[a][b]='X';
	}
	for(i=0;i<n;i++){
		cout<<sa[i]<<endl;
	}
}