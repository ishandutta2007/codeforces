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
const LL MAX=998244353;

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

const int N=210;
vector<vector<LL>> v1,v2(N,vector<LL>(2));

int t[110000];

int main(){
	int n,m;
	int i,j,k;
	LL a,b,c;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>t[i];
	}
	if(t[0]==-1)v1.assign(N,(vector<LL>){1,0});
	else{
		v1.assign(N,vector<LL>(2));
		v1[t[0]][0]=1;
	}
	for(i=1;i<n;i++){
		v2.assign(N,vector<LL>(2));
		for(j=1;j<=200;j++){
			v2[j+1][0]=v1[j][0]+v1[j][1];
			v2[j-1][1]=v1[j][1];
		}
		for(j=1;j<=200;j++)v2[j+1][0]+=v2[j][0];
		for(j=200;j>0;j--)v2[j-1][1]+=v2[j][1];
		for(j=1;j<=200;j++)v2[j][1]+=v1[j][0]+v1[j][1];
		for(j=1;j<=200;j++){
			for(k=0;k<2;k++){
				if(v2[j][k]>=MAX)v2[j][k]%=MAX;
			}
		}
		v1.assign(N,vector<LL>(2));
		for(j=1;j<=200;j++)for(k=0;k<2;k++)v1[j][k]=v2[j][k];
		if(t[i]==-1)continue;
		for(j=1;j<=200;j++){
			if(j!=t[i])v1[j][0]=0,v1[j][1]=0;
		}
	}
	a=0;
	for(j=1;j<=200;j++)a+=v1[j][1];
	cout<<a%MAX<<endl;
}