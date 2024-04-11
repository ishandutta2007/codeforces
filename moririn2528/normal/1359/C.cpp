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

void init(){
	
}

void solve(){
	int n,m;
	int i,j,k;
	int a,b,c;
	long double p,q,r,t;
	long double da,db;
	cin>>p>>q>>t;
	r=(p+q)/2;
	if(t>=p){
		cout<<1<<endl;
		return;
	}
	if(t<=r){
		cout<<2<<endl;
		return;
	}
	int z[3]={0,(int)1e7};
	while(z[1]-z[0]>1){
		z[2]=(z[0]+z[1])/2;
		da=(p*(z[2]+1)+q*z[2])/(z[2]*2+1);
		if(da<t)z[1]=z[2];
		else z[0]=z[2];
	}
	da=(p*(z[0]+1)+q*z[0])/(z[0]*2+1)-t;
	db=t-(p*(z[1]+1)+q*z[1])/(z[1]*2+1);
	if(da<=db)a=z[0];
	else a=z[1];
	cout<<2*a+1<<endl;
}

int main(){
	int n,i;
	init();
	cin>>n;
	for(i=0;i<n;i++){
		solve();
	}
}