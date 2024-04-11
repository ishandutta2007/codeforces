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

vector<LL> v1,v2;
LL n,m;

int check(){
	int i;
	for(i=0;i<n;i++){
		if(v1[i]!=v2[i])break;
	}
	if(i==n)return 10;
	for(i=0;i<n;i++){
		if(v1[n-i-1]!=v2[i])break;
	}
	if(i==n)return 20;
	for(i=0;i+1<n;i++){
		if(v2[i]>=v2[i+1])break;
	}
	if(i+1==n)return 1;
	for(i=0;i+1<n;i++){
		if(v2[i]<=v2[i+1])break;
	}
	if(i+1==n)return 2;
	return -1;
}

int main(){
	int i,j,k;
	LL a,b,c;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		v1.push_back(a);
	}
	for(i=0;i<n;i++){
		cin>>a;
		v2.push_back(a);
	}
	const int N=2e5;
	string sa;
	b=1;
	for(i=0;i<2e6;i++){
		a=check();
		if(a>=10)break;
		if(a==-1){
			cout<<"IMPOSSIBLE"<<endl;
			return 0;
		}
		if(a!=b)sa.push_back('R');
		sa.push_back('P');
		b=a;
		if(b==1){
			for(j=n-1;j>0;j--){
				v2[j]-=v2[j-1];
			}
		}else{
			for(j=0;j+1<n;j++){
				v2[j]-=v2[j+1];
			}
		}
	}
	if(i<=N){
		cout<<"SMALL"<<endl;
		a/=10;
		if(a!=b)sa.push_back('R');
		reverse(sa.begin(),sa.end());
		cout<<sa.size()<<endl;
		cout<<sa<<endl;
	}else{
		if(i<2e6){
			cout<<"BIG"<<endl;
			cout<<i<<endl;
			return 0;
		}
		if(v1[1]<v1[0])reverse(v1.begin(),v1.end());
		if(v2[1]<v2[0])reverse(v2.begin(),v2.end());
		b=i;
		while(v2[0]>v1[0]){
			b+=v2[1]/v2[0];
			v2[1]%=v2[0];
			swap(v2[0],v2[1]);
		}
		if(v2[0]){
			a=(v2[1]-v1[1])/v2[0];
			b+=a,v2[1]-=a*v2[0];
		}
		if(v2[0]!=v1[0] || v2[1]!=v1[1]){
			cout<<"IMPOSSIBLE";
			return 0;
		}
		cout<<"BIG"<<endl;
		cout<<b<<endl;
	}
}