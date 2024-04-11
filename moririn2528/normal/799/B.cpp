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

bool used[200005];
vector<P> v1[5];
int t[200005];
int s[200005];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>t[i];
	}
	for(i=0;i<2;i++){
		for(j=0;j<n;j++){
			cin>>a;
			a--;
			v1[a].push_back(make_pair(t[j],j));
		}
	}
	for(i=0;i<3;i++){
		sort(v1[i].rbegin(),v1[i].rend());
	}
	cin>>m;
	memset(s,-1,sizeof(s));
	for(i=0;i<m;i++){
		cin>>a;
		a--;
		while(!v1[a].empty()){
			b=v1[a].back().second;
			v1[a].pop_back();
			if(used[b])continue;
			used[b]=true;
			s[i]=t[b];
			break;
		}
	}
	array_show(s,m);
}