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
void array_show(vector<int> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%d%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%lld%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}

int num[110000][40];
vector<P> v1;

int main(){
	LL n,m;
	int i,j,k;
	LL a,b,c;
	cin>>n>>m;
	if(m==1){
		cout<<n*(n+1)/2<<endl;
		return 0;
	}
	for(i=2;i<1e5;i++){
		if(m%i)continue;
		for(a=0;m%i==0;a++)m/=i;
		v1.push_back(make_pair(i,a));
	}
	if(m!=1)v1.push_back(make_pair(m,1));
	for(i=0;i<n;i++){
		cin>>a;
		for(j=0;j<v1.size();j++){
			for(b=0;a%v1[j].first==0;b++)a/=v1[j].first;
			num[i][j]=b;
		}
	}
	for(j=0;j<n;j++){
		a=0;
		for(k=0;k<v1.size();k++){
			v1[k].second-=num[j][k];
			if(v1[k].second<=0)a++;
		}
		if(a==v1.size())break;
	}
	LL s=n-j;
	for(i=0;i<n;i++){
		for(k=0,a=0;k<v1.size();k++){
			v1[k].second+=num[i][k];
			if(v1[k].second<=0)a++;
		}
		if(a==v1.size()){
			s+=n-j;
			continue;
		}
		for(j++;j<n;j++){
			a=0;
			for(k=0;k<v1.size();k++){
				v1[k].second-=num[j][k];
				if(v1[k].second<=0)a++;
			}
			if(a==v1.size())break;
		}
		if(j>=n)break;
		s+=n-j;
	}
	cout<<s<<endl;
}