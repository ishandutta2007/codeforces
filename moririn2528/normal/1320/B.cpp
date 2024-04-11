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

queue<P> q1;
vector<int> rpath[220000];
int t[220000];
int dis[220000];
bool dbl[220000];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>a>>b;
		a--,b--;
		rpath[b].push_back(a);
	}
	cin>>m;
	for(i=0;i<m;i++){
		cin>>t[i];
		t[i]--;
	}
	memset(dis,-1,sizeof(dis));
	q1.push(make_pair(t[m-1],-1));
	for(i=0;!q1.empty();i++){
		j=q1.size();
		while(j--){
			a=q1.front().first,b=q1.front().second,q1.pop();
			if(dis[a]==i)dbl[a]=true;
			if(dis[a]!=-1)continue;
			dis[a]=i;
			for(auto to:rpath[a]){
				q1.push(make_pair(to,a));
			}
		}
	}
	int s[2]={0};
	for(i=0;i<m-1;i++){
		if(dis[t[i]]!=dis[t[i+1]]+1)s[0]++,s[1]++;
		else if(dbl[t[i]])s[1]++;
	}
	cout<<s[0]<<" "<<s[1]<<endl;
}