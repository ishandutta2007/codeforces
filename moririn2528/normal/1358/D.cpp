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
	LL n,m;
	int i,j,k;
	LL a,b,c,d;
	LL s=0;
	cin>>n>>m;
	b=0,c=0,d=0;
	for(i=0;i<n;i++){
		cin>>a;
		v1.push_back(a);
		b+=a*(a+1)/2,c+=a;
	}
	for(i=0,j=0;i<n;i++){
		if(c-(v1[j]-d)<m){
			a=c-m;
			c=m,b-=(2*d+a+1)*a/2;
			d+=a;
		}else{
			a=v1[j]-d;
			b-=(2*d+a+1)*a/2;
			c-=a,d=0,j++;
			if(j>=n)j-=n;
			while(c-v1[j]>=m){
				c-=v1[j],b-=v1[j]*(v1[j]+1)/2;
				j++;
				if(j>=n)j-=n;
			}
			a=c-m;
			d=a,c=m,b-=a*(a+1)/2;
		}
		s=max(s,b);
		b+=v1[i]*(v1[i]+1)/2,c+=v1[i];
	}
	cout<<s<<endl;

}