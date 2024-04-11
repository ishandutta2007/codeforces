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

vector<int> path[210000];
int dis[210000][2];

void check(int pos,int p){
	queue<int> q1;
	int a,b;
	int i,j;
	q1.push(pos);
	for(i=0;!q1.empty();i++){
		j=q1.size();
		while(j--){
			a=q1.front(),q1.pop();
			if(dis[a][p]!=-1)continue;
			dis[a][p]=i;
			for(auto to:path[a]){
				q1.push(to);
			}
		}
	}
}

int main(){
	int n,m,p;
	int i,j,k;
	int a,b,c;
	cin>>n>>m>>p;
	vector<int> v1;
	for(i=0;i<p;i++){
		cin>>a;
		a--;
		v1.push_back(a);
	}
	for(i=0;i<m;i++){
		cin>>a>>b;
		a--,b--;
		path[a].push_back(b);
		path[b].push_back(a);
	}
	memset(dis,-1,sizeof(dis));
	check(0,0);
	check(n-1,1);
	vector<tuple<int,int,int>> v2;
	for(auto num:v1){
		v2.push_back(make_tuple(dis[num][1],-dis[num][0],num));
	}
	sort(v2.rbegin(),v2.rend());
	int s=0;
	for(i=0;i+1<v2.size();i++){
		a=get<2>(v2[i]),b=get<2>(v2[i+1]);
		s=max(s,min(dis[a][0]+dis[b][1]+1,dis[b][0]+dis[a][1]+1));
	}
	cout<<min(dis[n-1][0],s)<<endl;
}