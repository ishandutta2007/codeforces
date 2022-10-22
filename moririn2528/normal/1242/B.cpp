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
#include<set>
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

vector<int> path[110000];
bool used[110000];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	set<int> s1,s2;
	vector<int> v1;
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>a>>b;
		a--,b--;
		path[a].push_back(b);
		path[b].push_back(a);
	}
	for(i=0;i<n;i++){
		s1.insert(i);
	}
	int s=-1;
	for(i=0;i<n;i++){
		if(used[i])continue;
		v1.clear();
		v1.push_back(i);
		s1.erase(i);
		s++;
		while(!v1.empty()){
			a=v1.back(),v1.pop_back();
			used[a]=true;
			for(auto to:path[a]){
				if(s1.find(to)!=s1.end()){
					s1.erase(to);
					s2.insert(to);
				}
			}
			swap(s1,s2);
			for(auto node:s2){
				v1.push_back(node);
			}
			s2.clear();
		}
	}
	cout<<s<<endl;
}