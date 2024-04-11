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

string sa[1100];
bool used[1100][1100];
int n,m;

void check(int x,int y){
	if(x<0 || x>=n || y<0 || y>=m)return;
	if(sa[x][y]=='.')return;
	if(used[x][y])return;
	used[x][y]=true;
	check(x+1,y);
	check(x-1,y);
	check(x,y+1);
	check(x,y-1);
}

int main(){
	int i,j,k;
	int a,b,c;
	int s=0;
	cin>>n>>m;
	c=0;
	for(i=0;i<n;i++){
		cin>>sa[i];
		a=0,b=0;
		for(j=1;j<m;j++){
			if(sa[i][j]=='.' && sa[i][j-1]=='#')a=1;
			if(a==1 && sa[i][j]=='#' && sa[i][j-1]=='.')s=-1;
		}
		for(j=0;j<m;j++){
			if(sa[i][j]=='#')b++;
		}
		if(b==0 && c==0)c=1;
	}
	for(j=0;j<m;j++){
		a=0,b=0;
		for(i=1;i<n;i++){
			if(sa[i][j]=='.' && sa[i-1][j]=='#')a=1;
			if(a==1 && sa[i][j]=='#' && sa[i-1][j]=='.')s=-1;
		}
		for(i=0;i<n;i++){
			if(sa[i][j]=='#')b++;
		}
		if(b==0 && c<2)c+=2;
	}
	if(c>0 && c<3)s=-1;
	if(s==-1){
		cout<<s<<endl;
		return 0;
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(used[i][j])continue;
			if(sa[i][j]=='.')continue;
			s++;
			check(i,j);
		}
	}
	cout<<s<<endl;
}