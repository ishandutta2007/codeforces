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

string sa[200];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n>>m;
	int x,y;
	a=500,b=0;
	for(i=0;i<n;i++){
		cin>>sa[i];
		for(j=0;j<m;j++){
			if(sa[i][j]=='W')continue;
			a=min(a,i),b=max(b,i);
		}
	}
	x=(a+b)/2;
	a=500,b=0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(sa[i][j]=='W')continue;
			a=min(a,j),b=max(b,j);
		}
	}
	y=(a+b)/2;
	cout<<x+1<<" "<<y+1<<endl;
}