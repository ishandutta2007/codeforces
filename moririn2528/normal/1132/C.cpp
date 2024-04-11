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

int cnt[5500];
int cnt2[5500][5500];
bool used[5500];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	int s=0;
	vector<int> v1;
	vector<tuple<int,int,int>> vt;
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>a>>b;
		a--;
		for(j=a;j<b;j++){
			if(used[j])continue;
			used[j]=true;
			s++;
		}
		vt.push_back(make_tuple(a,i,0));
		vt.push_back(make_tuple(b,i,1));
	}
	sort(vt.begin(),vt.end());
	memset(used,false,sizeof(used));
	for(i=0;i<vt.size();i++){
		tie(a,b,c)=vt[i];
		if(c==0)used[b]=true;
		else used[b]=false;
		if(i+1==vt.size() || a==get<0>(vt[i+1]))continue;
		a=get<0>(vt[i+1])-a;
		v1.clear();
		for(j=0;j<m;j++){
			if(used[j])v1.push_back(j);
		}
		if(v1.size()==1)cnt[v1[0]]+=a;
		if(v1.size()==2){
			cnt2[v1[0]][v1[1]]+=a;
			cnt2[v1[1]][v1[0]]+=a;
		}
	}
	b=n;
	for(i=0;i<m;i++){
		for(j=i+1;j<m;j++){
			a=cnt[i]+cnt[j]+cnt2[i][j];
			b=min(a,b);
		}
	}
	cout<<s-b<<endl;
}