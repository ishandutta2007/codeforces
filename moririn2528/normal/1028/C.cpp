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
#include<set>
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

int n,m;
int t[220000][4];

bool check(int x,int y){
	int i,j;
	for(i=0,j=0;i<n;i++){
		if(x<t[i][0] || t[i][2]<x || y<t[i][1] || t[i][3]<y)continue;
		j++;
	}
	if(j<n-1)return false;
	cout<<x<<" "<<y<<endl;
	return true;
}

int main(){
	int i,j,k;
	int a,b,c,d;
	int x,y;
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	for(i=0;i<n;i++){
		for(j=0;j<4;j++){
			cin>>t[i][j];
		}
	}
	a=0,b=0,c=0,d=0;
	for(i=0;i<n;i++){
		if(t[a][2]>t[i][2])a=i;
		if(t[b][0]<t[i][0])b=i;
		if(t[c][3]>t[i][3])c=i;
		if(t[d][1]<t[i][1])d=i;
	}
	
	assert(check(t[a][2],t[c][3])||check(t[a][2],t[d][1])||check(t[b][0],t[c][3])||check(t[b][0],t[d][1]));
}