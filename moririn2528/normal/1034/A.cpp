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

const int N=15000000;
int pri[20000000];
int cnt[N+10];

int gcd(int a,int b){
	if(a<b)swap(a,b);
	if(b==0)return a;
	return gcd(b,a%b);
}

int main(){
	int n,m;
	LL i,j,k;
	LL a,b,c;
	vector<LL> v1;
	for(i=2;i<=N;i++){
		if(pri[i])continue;
		pri[i]=i;
		for(j=i*i;j<=N;j+=i){
			if(pri[j]==0)pri[j]=i;
		}
	}
	cin>>n;
	c=0;
	for(i=0;i<n;i++){
		cin>>a;
		v1.push_back(a);
		c=gcd(c,a);
	}

	for(i=0;i<n;i++){
		a=v1[i]/c,b=0;
		while(a>1){
			if(b!=pri[a])b=pri[a],cnt[b]++;
			a/=b;
		}
	}
	a=0;
	for(i=0;i<=N;i++){
		if(cnt[i]>0 && cnt[i]<n)a=max(a,(LL)cnt[i]);
	}
	if(a==0)cout<<-1<<endl;
	else cout<<n-a<<endl;
}