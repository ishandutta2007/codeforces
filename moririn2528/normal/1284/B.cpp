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

const int M=1e6+7;
int num[1100000];
int t[1100000];
vector<int> vs;

int main(){
	LL n,m;
	int i,j,k;
	int a,b,c;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>m;

		for(j=0;j<m;j++){
			cin>>t[j];
		}
		for(j=0;j<m-1;j++){
			if(t[j]<t[j+1])break;
		}
		if(j==m-1){
			num[t[0]]++;
			vs.push_back(t[m-1]);
		}
	}
	for(i=0;i<M;i++){
		num[i+1]+=num[i];
	}
	LL s=n*n;
	for(auto node:vs){
		s-=num[node];
	}
	cout<<s<<endl;
}