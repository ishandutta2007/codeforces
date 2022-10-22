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

vector<LL> v1;

int main(){
	int n,m;
	int i,j,k;
	LL a,b,c;
	string sa;
	LL s=0;
	cin>>n;
	v1.push_back(1);
	a=1;
	for(i=0;i<n;i++){
		cin>>sa;
		if(sa=="for"){
			cin>>b;
			if(a!=-1)a*=b;
			if(a>=((LL)1<<32))a=-1;
			v1.push_back(a);
		}else if(sa=="end"){
			v1.pop_back();
			a=v1.back();
		}else if(a==-1){
			s=-1;
			break;
		}else{
			s+=a;
			if(s>=((LL)1<<32)){
				s=-1;
				break;
			}
		}
	}
	if(s==-1)cout<<"OVERFLOW!!!"<<endl;
	else cout<<s<<endl;
}