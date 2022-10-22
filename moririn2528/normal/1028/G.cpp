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

void array_show(vector<LL> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	printf("%d ",vec_n);
	for(int i=0;i<vec_n;i++)printf("%lld%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
	cout<<flush;
}

const LL range_max=1e4;

void check(LL pos,LL n){
	LL m=min(pos,range_max);
	int i,j,k;
	LL a,b,c;
	vector<LL> vs;
	if(n<=m){
		for(i=0;i<n;i++){
			vs.push_back(pos+i);
		}
		array_show(vs);
		return;
	}
	a=n/(m+1)+1;
	for(i=0;i<m;i++){
		b=pos+a*(i+1)-1;
		if(b>=pos+n)break;
		vs.push_back(b);
	}
	array_show(vs);
	cin>>b;
	if(b==-1)return;
	if(b==0){
		check(pos,a-1);
		return;
	}
	if(b==vs.size()){
		b=vs.back()+1;
		check(b,pos+n-b);
		return;
	}
	check(vs[b-1]+1,a-1);
}

int print_one(LL a){
	cout<<1<<" "<<a<<endl;
	cin>>a;
	return a;
}

int main(){
	int i,j,k;
	LL a,b,c;
	const LL n=10004205361450474,n2=204761410474;
	vector<LL> vs;
	a=print_one(n2);
	if(a==-1)return 0;
	if(a==1){
		check(n2+1,n-n2);
		return 0;
	}
	a=print_one(2046);
	if(a==-1)return 0;
	if(a==1){
		vector<LL> vsa={4094,8190,16382};
		for(i=3;i<2047;i++){
			a=vsa.back()+range_max+1;
			vsa.push_back(a);
		}
		vector<LL> vsb={vsa.back()+range_max+1};
		b=(range_max+1)*(range_max+1);
		for(i=1;i<2047;i++){
			a=vsb.back()+b;
			vsb.push_back(a);
		}
		array_show(vsb);
		cin>>a;
		if(a==-1)return 0;
		if(a>0){
			check(vsb[a-1]+1,vsb[a]-vsb[a-1]-1);
			return 0;
		}
		array_show(vsa);
		cin>>a;
		if(a==-1)return 0;
		if(a>0)check(vsa[a-1]+1,vsa[a]-vsa[a-1]-1);
		else check(2047,2047);
		return 0;
	}
	a=print_one(6);
	if(a==-1)return 0;
	if(a==0){
		a=print_one(2);
		if(a==-1)return 0;
		if(a==0)print_one(1);
		else{
			cout<<"3 3 4 5"<<endl;
		}
		return 0;
	}
	vs={14,30,62,126,254,510,1022};
	array_show(vs);
	cin>>a;
	if(a==-1)return 0;
	if(a==0)check(7,7);
	else{
		check(vs[a-1]+1,vs[a-1]+1);
	}
}