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

int num[100];

int main(){
	LL n,m;
	int i,j,k;
	LL a,b,c;
	int tes;
	bool flag;
	cin>>tes;
	while(tes--){
		memset(num,0,sizeof(num));
		cin>>n>>m;
		for(i=0;i<m;i++){
			cin>>a;
			a=__builtin_ffsll(a)-1;
			num[a]++;
		}
		flag=true;
		int s=0;
		for(i=0;i<60;i++){
			if(num[i]>0){
				if(n&((LL)1<<i))num[i]--;
				num[i+1]+=num[i]/2;
				continue;
			}
			if((n&((LL)1<<i))==0)continue;
			for(j=i+1;j<70;j++){
				s++;
				if(num[j]){
					num[j]--;
					break;
				}
				num[j]=1;
			}
			if(j>=70){
				flag=false;
				break;
			}
		}
		if(!flag)s=-1;
		cout<<s<<endl;
	}
}