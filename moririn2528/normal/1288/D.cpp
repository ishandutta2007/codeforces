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

int used[1000];
int num[330000];
vector<tuple<int,int,int> > v1;

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n>>m;
	memset(used,-1,sizeof(used));
	used[0]=0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>a;
			v1.push_back(make_tuple(a,i,j));
		}
	}
	sort(v1.rbegin(),v1.rend());
	for(auto node:v1){
		tie(a,b,c)=node;
		num[b]+=1<<c;
		c=num[b];
		if(used[c]!=-1)continue;
		for(i=0;i<(1<<m);i++){
			if((i&c)!=i)continue;
			if(used[i]!=-1)continue;
			used[i]=b;
			j=(1<<m)-i-1;
			if(used[j]!=-1){
				cout<<used[j]+1<<" "<<b+1<<endl;
				return 0;
			}
		}
	}
}