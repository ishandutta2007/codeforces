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
	for(int i=0;i<vec_n;i++)printf("%d%c",vec_s[i]+1,(i!=vec_n-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%lld%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}

vector<int> path[110000];
bool used[110000];
vector<int> v1,v4;

bool check(int pos,int bef){
	v1.push_back(pos);
	if(used[pos])return true;
	used[pos]=true;
	for(auto to:path[pos]){
		if(to==bef)continue;
		if(check(to,pos))return true;
	}
	v1.pop_back();
	return false;
}

void check2(int pos,int a){
	if(used[pos])return;
	used[pos]=true;
	if(a)v1.push_back(pos);
	else v4.push_back(pos);
	for(auto to:path[pos]){
		check2(to,1-a);
	}
}

int main(){
	int n,m,p;
	int i,j,k;
	int a,b,c;
	vector<int> v2,v3;
	cin>>n>>m>>p;
	for(i=0;i<m;i++){
		cin>>a>>b;
		a--,b--;
		path[a].push_back(b);
		path[b].push_back(a);
	}
	for(i=0;i<n;i++){
		if(used[i])continue;
		if(check(i,-1))break;
	}
	if(i<n){
		reverse(v1.begin(),v1.end());
		while(v1.back()!=v1[0])v1.pop_back();
		v2.push_back(v1[0]);
		memset(used,false,sizeof(used));
		bool flag=false;
		for(i=1;i+1<v1.size();i++){
			for(auto to:path[v1[i]]){
				if(to==v2.back())continue;
				if(to==v2[0])flag=true;
				else if(used[to]){
					while(v2.back()!=to){
						used[v2.back()]=false;
						v2.pop_back();
					}
				}
			}
			v2.push_back(v1[i]);
			used[v1[i]]=true;
			if(flag)break;
		}
		if(v2.size()>p){
			for(i=0;i<(p+1)/2;i++){
				v3.push_back(v2[i*2]);
			}
			cout<<1<<endl;
			array_show(v3);
		}else{
			cout<<2<<endl<<v2.size()<<endl;
			array_show(v2);
		}
		return 0;
	}
	memset(used,false,sizeof(used));
	for(i=0;i<n;i++){
		if(used[i])continue;
		v1.clear(),v4.clear();
		check2(i,0);
		if(v1.size()<v4.size())swap(v1,v4);
		while(v2.size()<(p+1)/2 && !v1.empty()){
			v2.push_back(v1.back());
			v1.pop_back();
		}
	}
	cout<<1<<endl;
	array_show(v2);
}