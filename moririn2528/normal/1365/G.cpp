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

int main(){
	int n,m;
	int i,j,k;
	LL a,b,c;
	const int N=13,M=6;
	vector<LL> v1[N],v2;
	cin>>n;
	for(i=0,j=0;i<(1<<N);i++){
		if(__builtin_popcount(i)==M){
			v2.push_back(i);
			for(k=0;k<N;k++){
				if(i&(1<<k))v1[k].push_back(j+1);
			}
			j++;
		}
		if(j==n)break;
	}
	vector<LL> v3(N);
	for(i=0;i<N;i++){
		if(v1[i].empty())continue;
		cout<<"? "<<v1[i].size();
		for(auto num:v1[i])cout<<" "<<num;
		cout<<endl;
		cin>>a;
		v3[i]=a;
	}
	cout<<"!";
	for(i=0;i<n;i++){
		a=0;
		for(j=0;j<N;j++){
			if(v2[i]&(1<<j))continue;
			a|=v3[j];
		}
		cout<<" "<<a;
	}
	cout<<endl;
}