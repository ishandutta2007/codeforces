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

int t[110000][2];
vector<int> s;

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	bool flag=true;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a;
		t[a][0]++,t[a][1]=i+1;
	}
	for(i=0;i<m;i++){
		cin>>a;
		if(t[a][0]==0){
			cout<<"Impossible"<<endl;
			return 0;
		}
		if(t[a][0]>=2)flag=false;
		s.push_back(t[a][1]);
	}
	if(flag){
		cout<<"Possible"<<endl;
		array_show(s);
	}else cout<<"Ambiguity"<<endl;
}