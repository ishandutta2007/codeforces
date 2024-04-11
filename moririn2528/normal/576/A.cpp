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

vector<P> v1[1100];
vector<int> vs;
int t[1100];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n;
	for(i=0;i<n;i++){
		v1[0].push_back(make_pair(i+1,0));
	}
	k=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			a=v1[i][j].first;
			if(a%(i+2)==0)v1[i+1].push_back(v1[i][j]);
		}
		b=v1[i].back().second+1;
		for(j=0;j<n;j++){
			a=v1[i][j].first;
			v1[i][j].second+=b;
			if(a%(i+2)!=0)v1[i+1].push_back(v1[i][j]);
		}
		a=-1,b=-1;
		for(j=0;j<n;j++){
			if(a!=v1[i+1][j].second)a=v1[i+1][j].second,b++;
			v1[i+1][j].second=b;
		}
		b=v1[i+1].back().second;
		if(k!=b)k=b,vs.push_back(i+2);
		if(b==n-1)break;
	}
	cout<<vs.size()<<endl;;
	array_show(vs);
}