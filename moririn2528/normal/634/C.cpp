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

int num[1000005][2];
int tt[200005];

int bit_update(int t,int a,int b){
	num[t][0]+=a,num[t][1]+=b;
	for(int i=0;i<18;i++){
		if(t&(1<<i)){
			t+=(1<<i);
			num[t][0]+=a,num[t][1]+=b;
		}
	}
}

int bit_search(int t,int p){
	int i,j;
	int a=0;
	int s=0;
	for(i=0;(1<<i)<t;i++);
	for(;i>=0;i--){
		if(t&(1<<i)){
			a+=(1<<i);
			s+=num[a][p];
		}
	}
	return s;
}

int main(){
	int n,m,q,x,y;
	int i,j,k;
	int a,b,c,d,e;
	int rui=0,rui2=0;
	cin>>n>>m>>x>>y>>q;
	for(i=0;i<q;i++){
		cin>>a;
		if(a==1){
			cin>>a>>b;
			d=min(b,y-tt[a]);
			e=min(b,x-tt[a]);
			if(d<0)d=0;
			if(e<0)e=0;
			bit_update(a,d,e);
			rui+=b,rui2+=e;
			tt[a]+=b;
		}else{
			cin>>a;
			d=bit_search(a-1,0);
			d+=rui2-bit_search(a+m-1,1);
			cout<<d<<endl;
		}
	}
}