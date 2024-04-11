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

vector<pair<LL,LL> > v1; 

int main(){
	int n,m;
	int i,j,k;
	LL a,b,c;
	LL x,y;
	double ma[2],p,q,r;
	cin>>n;
	cin>>x>>y;
	for(i=0;i<n;i++){
		cin>>a>>b;
		v1.push_back(make_pair(a-x,b-y));
	}
	v1.push_back(v1[0]);
	ma[0]=(LL)1<<40,ma[1]=0;
	for(i=0;i<n;i++){
		p=v1[i].first*v1[i].first+v1[i].second*v1[i].second;
		ma[0]=min(ma[0],p);
		ma[1]=max(ma[1],p);
		a=v1[i+1].first-v1[i].first,b=v1[i+1].second-v1[i].second;
		c=-a*v1[i].first-b*v1[i].second;
		if(0<=c && c<=a*a+b*b){
			p=(double)c/(double)(a*a+b*b);
			q=v1[i+1].first*p+v1[i].first*(1-p);
			r=v1[i+1].second*p+v1[i].second*(1-p);
			p=q*q+r*r;
			ma[0]=min(ma[0],p);
		}
	}
	p=ma[1]-ma[0];
	p*=acos(-1);
	cout<<fixed<<setprecision(10)<<p<<endl;
}