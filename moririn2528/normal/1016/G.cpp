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
typedef pair<LL,LL> P;
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

vector<P> v1;
vector<int> v2;
vector<LL> vt;
vector<LL> vs(1<<20);

LL gcd(LL a,LL b){
	if(a<b)swap(a,b);
	if(b==0)return a;
	return gcd(b,a%b);
}

int main(){
	int n,m;
	int i,j,k;
	LL a,b,c;
	LL x,y;
	LL s=0;
	cin>>n>>x>>y;
	for(i=0;i<n;i++){
		cin>>a;
		vt.push_back(a);
	}
	if(y%x){
		cout<<0<<endl;
		return 0;
	}
	a=y;
	for(i=2;i<1e6;i++){
		if(a==1)break;
		if(a%i)continue;
		for(j=0,b=1;a%i==0;j++){
			a/=i,b*=i;
		}
		if(x%b==0)continue;
		v1.push_back(make_pair(i,j));
	}
	if(a!=1 && x%a){
		if(gcd(x,a)!=1){
			a/=gcd(x,a);
			v1.push_back(make_pair(a,1));
		}else{
			for(i=0;i<n;i++){
				b=gcd(a,vt[i]);
				if(b!=1 && b!=a){
					if(b*b==a)v1.push_back(make_pair(b,2));
					else{
						v1.push_back(make_pair(b,1));
						v1.push_back(make_pair(a/b,1));
					}
					break;
				}
			}
			if(i==n)v1.push_back(make_pair(a,1));
		}
	}
	b=x;
	for(i=0;i<v1.size();i++){
		for(j=0;b%v1[i].first==0;j++)b/=v1[i].first;
		v2.push_back(j);
	}
	m=v1.size();
	for(i=0;i<n;i++){
		if(vt[i]%x)continue;
		a=vt[i],b=0;
		for(k=0;k<m;k++){
			for(j=0;a%v1[k].first==0;j++)a/=v1[k].first;
			if(v2[k]!=j)b+=1<<k;
		}
		vs[b]++;
	}
	for(i=0;i<m;i++){
		for(j=0;j<(1<<m);j++){
			if(j&(1<<i))vs[j]+=vs[j-(1<<i)];
		}
	}
	for(i=0;i<n;i++){
		if(y%vt[i])continue;
		a=vt[i],b=0;
		for(k=0;k<m;k++){
			for(j=0;a%v1[k].first==0;j++)a/=v1[k].first;
			if(v1[k].second!=j)b+=1<<k;
		}
		b^=(1<<m)-1;
		s+=vs[b];
	}
	cout<<s<<endl;

}