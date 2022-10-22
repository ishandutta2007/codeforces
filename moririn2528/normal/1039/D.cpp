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

P dfs(int pos,int bef,int val){
	P pa=make_pair(0,0);
	P pb;
	int a=0,b=0;
	for(auto to:path[pos]){
		if(to==bef)continue;
		pb=dfs(to,pos,val);
		pa.first+=pb.first;
		if(a<pb.second)swap(a,pb.second);
		if(b<pb.second)swap(b,pb.second);
	}
	if(a+b+1>=val)pa.first++;
	else pa.second=a+1;
	return pa;
}

const int B=330;

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n;
	vector<int> vs(n);
	for(i=0;i<n-1;i++){
		cin>>a>>b;
		a--,b--;
		path[a].push_back(b);
		path[b].push_back(a);
	}
	for(i=0;i<B && i<n;i++){
		vs[i]=dfs(0,-1,i+1).first;
	}
	if(n<=B){
		array_show(vs,vs.size(),'\n');
		return 0;
	}
	a=B;
	int z[3];
	vector<int> vz(B,n);
	for(i=B-1;i>=0;i--){
		z[0]=a-1,z[1]=vz[i];
		while(z[1]-z[0]>1){
			z[2]=(z[0]+z[1])/2;
			b=dfs(0,-1,z[2]+1).first;
			if(b<=i){
				z[1]=z[2];
				vz[b]=min(vz[b],z[2]);
			}else z[0]=z[2];
		}
		for(j=a;j<z[1];j++){
			vs[j]=i+1;
		}
		for(j=1;j<i;j++){
			vz[j]=min(vz[j],vz[j-1]);
		}
		a=z[1];
	}
	array_show(vs,vs.size(),'\n');
}