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

int t[2][110000];
int st[2][110000];
int n,m;
int sa;

void check(int x,int y){
	if(x<0 || x>=2 || y<0 || y>=n)return;
	if(t[x][y]==0){
		sa-=st[x][y];
		st[x][y]=0;
		return;
	}
	int i,j;
	int s=0;
	i=1-x;
	for(j=y;j<=y+1;j++){
		if(j<0 || j>=n)continue;
		if(t[i][j])s=1;
	}
	sa-=st[x][y];
	st[x][y]=s;
	sa+=st[x][y];
}

int main(){
	int i,j,k;
	int a,b,c;
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>a>>b;
		a--,b--;
		t[a][b]=1-t[a][b];
		check(a,b);
		check(1-a,b-1);
		check(1-a,b);
		check(1-a,b+1);
		if(sa==0)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}