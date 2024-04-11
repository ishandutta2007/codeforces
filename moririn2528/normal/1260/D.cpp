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

LL gcd(LL a,LL b){
	if(b==0)return a;
	return gcd(b,a%b);
}

vector<int> v1;
vector<P> path[200005];
int n,m,p,t;

bool check(int x){
	int a,b,c;
	int i,j,k;
	a=0,b=0;
	for(i=0;i<n;i++){
		for(auto node:path[i]){
			if(node.second<=x)continue;
			a=max(a,node.first);
		}
		if(i<a)b++;
	}
	//cout<<x<<" "<<a<<" "<<b<<endl;
	if(b*2<=t-n)return true;
	return false;
}

int main(){
	int i,j,k;
	LL a,b,c,d;
	LL s=0;
	cin>>m>>n>>p>>t;
	n++;
	for(i=0;i<m;i++){
		cin>>a;
		v1.push_back(a);
	}
	sort(v1.begin(),v1.end());
	d=v1.back();
	for(i=0;i<p;i++){
		cin>>a>>b>>c;
		a--;
		path[a].push_back(make_pair(b,c));
	}
	int z[3]={-1,m};
	while(z[1]-z[0]>1){
		z[2]=(z[0]+z[1])/2;
		if(check(v1[z[2]]))z[1]=z[2];
		else z[0]=z[2];
	}
	cout<<m-z[1]<<endl;
}