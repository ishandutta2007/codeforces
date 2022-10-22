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

const int N=60;

int prim_num[100];
vector<int> v1(100);

long long int powA(long long int p_a,long long int p_n){
	//p_a^p_n
	long long int p_b=1,p_t=1;
	for(;p_b<=p_n;p_b<<=1);
	for(p_b>>=1;p_b>0;p_b>>=1){
		if(p_t>1e9)return -1;
		p_t*=p_t;
		if(p_n&p_b){
			if(p_t>((LL)1<<60)/p_a)return -1;
			p_t*=p_a;
		}
	}
	return p_t;
}

int main(){
	LL n,m;
	int i,j,k;
	LL a,b,c;
	LL tes;
	cin>>tes;
	for(i=2;i<=N;i++){
		a=i;
		for(j=2;j<=N;j++){
			if(a%j)continue;
			prim_num[i]++;
			a/=j;
			if(a%j==0){
				prim_num[i]=-1;
				break;
			}
			if(a==1)break;
		}
	}
	v1[2]=1e9,v1[3]=1e6,v1[4]=1e5,v1[5]=1e4;
	v1[10]=100,v1[20]=10;
	for(i=2;i<=N;i++){
		if(v1[i]==0)v1[i]=v1[i-1];
	}
	LL s=0;
	while(tes--){
		cin>>n;
		s=n-1;
		for(i=2;i<=N;i++){
			if(prim_num[i]==-1)continue;
			LL z[3]={1,v1[i]+1};
			while(z[1]-z[0]>1){
				z[2]=(z[0]+z[1])/2;
				a=powA(z[2],i);
				if(a==-1 || n<a)z[1]=z[2];
				else z[0]=z[2];
			}
			a=z[0]-1;
			if(prim_num[i]%2==1)s-=a;
			else s+=a;
		}
		cout<<s<<endl;
	}
}