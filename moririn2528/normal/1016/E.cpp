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

int n,m;
vector<LL> v1;
LL t[210000];

long double dis(long double pos){
	LL pn=pos;
	auto itr=upper_bound(v1.begin(),v1.end(),pn);
	if(itr==v1.end())return t[n];
	int i=distance(v1.begin(),itr);
	if(i%2==0)return t[i/2];
	long double s=t[i/2];
	pos-=v1[i-1];
	return pos+s;
}

int main(){
	int i,j,k;
	LL a,b,c;
	LL p,q,r;
	long double da,db;
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>r>>p>>q;
	r=-r;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a>>b;
		v1.push_back(a);
		v1.push_back(b);
		t[i+1]=t[i]+b-a;
	}
	cin>>m;
	for(i=0;i<m;i++){
		cin>>a>>b;
		da=dis(a+(long double)(q-a)*b/(r+b))-dis(a+(long double)(p-a)*b/(r+b));
		da=da*(r+b)/b;
		cout<<fixed<<setprecision(10)<<da<<endl;
	}
}