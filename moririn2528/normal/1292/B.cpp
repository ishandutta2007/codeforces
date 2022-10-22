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
typedef pair<LL,LL> P;
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

int main(){
	int n,m;
	int i,j,k;
	LL a,b,c,d;
	LL x0,y0,ax,ay,bx,by;
	vector<P> v1;
	LL xs,ys,t;
	int s=0;
	cin>>x0>>y0>>ax>>ay>>bx>>by;
	cin>>xs>>ys>>t;
	v1.push_back(make_pair(x0,y0));
	d=1;
	for(i=0;i<16;i++){
		d*=10;
	}
	for(i=0;i<60;i++){
		a=v1.back().first,b=v1.back().second;
		a=a*ax+bx,b=b*ay+by;
		c=abs(a-v1.back().first)+abs(b-v1.back().second);
		v1.push_back(make_pair(a,b));
		if(c>d)break;
	}
	m=v1.size();
	for(i=0;i<m;i++){
		a=0;
		for(j=i;j<m;j++){
			b=abs(xs-v1[i].first)+abs(ys-v1[i].second);
			c=abs(xs-v1[j].first)+abs(ys-v1[j].second);
			b=min(b,c);
			if(a+b<=t)s=max(s,j-i+1);
			if(a>t)break;
			if(j+1<m){
				a+=v1[j+1].first-v1[j].first-v1[j].second+v1[j+1].second;
			}
		}
	}
	cout<<s<<endl;
}