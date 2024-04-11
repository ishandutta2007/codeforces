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

bool used[10005];
int s[100];
vector<P> v1;

int func(int a){
	int i,j,k;
	int b,c;
	b=1;
	for(j=0;j<4;j++,b*=10){
		c=a-a%(b*10)/b*b;
		for(k=0;k<10;k++,c+=b){
			if(!used[c]){
				used[c]=true;
				return c;
			}
		}
	}
	return 0;
}

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	scanf("%d",&m);
	while(m--){
		scanf("%d",&n);
		memset(used,false,sizeof(used));
		v1.clear();
		b=0;
		for(i=0;i<n;i++){
			cin>>a;
			if(!used[a]){
				used[a]=true;
				s[i]=a;
			}else{
				v1.push_back(make_pair(a,i));
			}
		}
		printf("%d\n",v1.size());
		for(auto node:v1){
			s[node.second]=func(node.first);
		}
		for(i=0;i<n;i++){
			printf("%04d\n",s[i]);
		}
	}
}