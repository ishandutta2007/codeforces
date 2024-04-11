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

bool good[220000];
LL t[220000];

LL gcd(LL a,LL b){
	if(a<b)swap(a,b);
	if(b==0)return a;
	return gcd(b,a%b);
}

int main(){
	int n,m;
	int i,j,k;
	LL a,b,c;
	LL s=1;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>t[i];
	}
	if(n==2){
		a=t[0]*t[1];
		a/=gcd(t[0],t[1]);
		cout<<a<<endl;
		return 0;
	}
	vector<int> v1;
	for(i=2;i<500;i++){
		if(good[i])continue;
		for(j=i*2;j<=500;j+=i){
			good[j]=true;
		}
		v1.clear();
		for(j=0;j<n;j++){
			for(k=0;t[j]%i==0;k++){
				t[j]/=i;
			}
			v1.push_back(k);
		}
		sort(v1.begin(),v1.end());
		s*=pow((LL)i,v1[1]);
	}
	v1.clear();
	for(i=0;i<n;i++){
		v1.push_back(t[i]);
	}
	sort(v1.begin(),v1.end());
	if(v1[0]==v1[n-2])s*=v1[0];
	else if(v1[1]==v1[n-1])s*=v1[1];
	cout<<s<<endl;
}