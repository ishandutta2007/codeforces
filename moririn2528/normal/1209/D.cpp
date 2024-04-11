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

vector<int> path[100005];
bool used[100005];

void check(int a){
	if(used[a])return;
	used[a]=true;
	for(int i=0;i<path[a].size();i++){
		check(path[a][i]);
	}
}

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>a>>b;
		a--,b--;
		path[a].push_back(b);
		path[b].push_back(a);
	}
	int s=m-n;
	for(i=0;i<n;i++){
		if(used[i])continue;
		s++;
		check(i);
	}
	cout<<s<<endl;
}