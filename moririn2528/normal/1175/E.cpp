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

int t[2][550000][2];
int nex[30][550000];
int nex2[550000];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	vector<P> v1;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a>>b;
		t[0][i][0]=a,t[0][i][1]=b;
		v1.push_back(make_pair(a,i));
		v1.push_back(make_pair(b,n+i));
	}
	for(i=0;i<m;i++){
		cin>>a>>b;
		t[1][i][0]=a,t[1][i][1]=b;
		v1.push_back(make_pair(a,2*n+i));
	}
	sort(v1.begin(),v1.end());
	a=-1,b=-1;
	for(auto node:v1){
		if(node.second<n){
			if(a<t[0][node.second][1])a=t[0][node.second][1],b=node.second;
		}else if(node.second<2*n){
			nex[0][node.second-n]=b;
		}else{
			nex2[node.second-2*n]=b;
		}
	}
	for(i=0;i<20;i++){
		for(j=0;j<n;j++){
			a=nex[i][j];
			if(a!=-1)a=nex[i][a];
			nex[i+1][j]=a;
		}
	}
	for(i=0;i<m;i++){
		a=nex2[i];
		if(a==-1){
			cout<<-1<<endl;
			continue;
		}
		int s=1;
		for(j=20;j>=0;j--){
			b=nex[j][a];
			if(b==-1)continue;
			if(t[0][b][1]<t[1][i][1])s+=(1<<j),a=b;
		}
		if(a==-1){
			cout<<-1<<endl;
			continue;
		}
		if(t[0][a][1]>=t[1][i][1]){
			cout<<s<<endl;
			continue;
		}
		a=nex[0][a];
		if(a==-1 || t[0][a][1]<t[1][i][1])cout<<-1<<endl;
		else cout<<s+1<<endl;
	}
}