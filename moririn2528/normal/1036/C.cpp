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

LL check(LL t){
	LL cnt[10];
	if(t<=1e3)return t+1;
	vector<int> v1;
	while(t>0){
		v1.push_back(t%10);
		t/=10;
	}
	reverse(v1.begin(),v1.end());
	int a=3;
	int i,j,k;
	LL s=0;
	for(i=0;i<v1.size();i++){
		if(v1[i]==0)continue;
		memset(cnt,0,sizeof(cnt));
		cnt[0]=1,cnt[1]=v1[i]-1;
		for(j=i+1;j<v1.size();j++){
			for(k=3;k>=0;k--){
				cnt[k+1]+=9*cnt[k];
			}
		}
		for(j=0;j<=a;j++){
			s+=cnt[j];
		}
		a--;
	}
	if(a>=0)s++;
	return s;
}

int main(){
	int n,m;
	int i,j,k;
	LL a,b,c;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a>>b;
		cout<<check(b)-check(a-1)<<endl;
	}
}