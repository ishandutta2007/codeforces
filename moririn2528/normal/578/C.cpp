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

int main(){
	int n,m;
	int i,j,k;
	double a,b,c;
	vector<double> v1;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		v1.push_back(a);
	}
	double z[3]={-1e4,1e4};
	double s[2]={0,0};
	for(i=0;i<100;i++){
		z[2]=(z[0]+z[1])/2;
		a=0,b=0,c=0;
		s[0]=0,s[1]=0;
		for(j=0;j<n;j++){
			a+=v1[j]-z[2];
			b=max(a,b);
			c=min(a,c);
			s[0]=max(s[0],a-c);
			s[1]=min(s[1],a-b);
		}
		s[1]=-s[1];
		if(s[0]<s[1])z[1]=z[2];
		else z[0]=z[2];
	}
	cout<<fixed<<setprecision(10)<<max(s[0],s[1])<<endl;
}