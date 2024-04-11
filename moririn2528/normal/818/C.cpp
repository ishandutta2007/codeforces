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

int t[110000][4];
int num[110000][4];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c,d;
	int s[4];
	vector<P> v1,v2;
	cin>>n;
	cin>>a>>b;
	for(i=0;i<n;i++){
		for(j=0;j<4;j++){
			cin>>t[i][j];
		}
		if(t[i][0]>t[i][2])swap(t[i][0],t[i][2]);
		if(t[i][1]>t[i][3])swap(t[i][1],t[i][3]);
		v1.push_back(make_pair(t[i][0],i));
		v2.push_back(make_pair(t[i][2],i));
		if(t[i][0]==t[i][2]){
			num[i][2]=-1,num[i][3]=-1;
		}else{
			num[i][0]=-1,num[i][1]=-1;
		}
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	i=0;
	for(auto node:v2){
		for(;i<v1.size() && v1[i].first<node.first;i++);
		num[node.second][0]+=i;
	}
	i=0;
	for(auto node:v1){
		for(;i<v2.size() && v2[i].first<=node.first;i++);
		num[node.second][1]+=v2.size()-i;
	}
	v1.clear(),v2.clear();
	for(i=0;i<n;i++){
		v1.push_back(make_pair(t[i][1],i));
		v2.push_back(make_pair(t[i][3],i));
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	i=0;
	for(auto node:v2){
		for(;i<v1.size() && v1[i].first<node.first;i++);
		num[node.second][2]+=i;
	}
	i=0;
	for(auto node:v1){
		for(;i<v2.size() && v2[i].first<=node.first;i++);
		num[node.second][3]+=v2.size()-i;
	}
	for(i=0;i<4;i++){
		cin>>s[i];
	}
	for(i=0;i<n;i++){
		for(j=0;j<4;j++){
			if(num[i][j]!=s[j])break;
		}
		if(j==4){
			cout<<i+1<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
}