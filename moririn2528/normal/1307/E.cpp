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

long long int pow_mod(long long int p_a,long long int p_n,long long int p_p=1e9+7){
	//p_a^p_n mod p_p
	long long int p_b=1,p_t=1;
	for(;p_b<=p_n;p_b<<=1);
	for(p_b>>=1;p_b>0;p_b>>=1){
		p_t*=p_t;
		if(p_t>=p_p)p_t%=p_p;
		if(p_n&p_b)p_t*=p_a;
		if(p_t>=p_p)p_t%=p_p;
	}
	return p_t;
}

vector<int> v1,v2;
int t[10000][5];
bool used[10000];
LL cnt[10000][5];

int main(){
	int n,m;
	int i,j,k;
	LL a,b,c,d;
	LL s[2]={0,1};
	map<P,int> m1;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a;
		v1.push_back(a);
		cnt[a][0]++;
	}
	for(i=0;i<m;i++){
		cin>>a>>b;
		if(cnt[a][0]<b)continue;
		m1[make_pair(a,b)]=1;
		cnt[a][3]++;
	}
	for(i=0;i<=n;i++){
		if(cnt[i][3]==0)continue;
		s[0]++;
		s[1]*=cnt[i][3];
		if(s[1]>=MAX)s[1]%=MAX;
	}
	for(i=0;i<n;i++){
		a=v1[i];
		if(m1.find(make_pair(a,cnt[a][0]-cnt[a][1]))!=m1.end()){
			cnt[a][3]--;
		}
		cnt[a][1]++;
		if(m1.find(make_pair(a,cnt[a][1]))==m1.end())continue;
		cnt[a][2]++;
		c=1,d=1;
		for(j=0;j<=n;j++){
			a=cnt[j][2],b=cnt[j][3];
			if(j==v1[i]){
				a=0;
				if(cnt[j][0]-cnt[j][1]>=cnt[j][1])b--;
			}
			if(a>b)swap(a,b);
			if(b==0)continue;
			if(a==0)c++,d*=b;
			else if(b==1)c++,d*=2;
			else{
				c+=2,d*=a*(b-1);
			}
			if(d>=MAX)d%=MAX;
		}
		//cout<<i<<" "<<c<<" "<<d<<endl;
		if(s[0]<c)s[0]=c,s[1]=d;
		else if(s[0]==c)s[1]+=d;
		if(s[1]>=MAX)s[1]%=MAX;
	}
	cout<<s[0]<<" "<<s[1]%MAX<<endl;
}