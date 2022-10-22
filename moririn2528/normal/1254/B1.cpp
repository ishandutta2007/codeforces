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

LL t[1000005];
LL ta[1000005],tb[1000005];
bool np[1000005];
LL n,m;
LL a,b,c,d,e;

LL check(LL i){
	LL j,k;
	tb[0]=0,b=0;
	for(j=0;j<n;j++){
		if(t[j]>=i)ta[j]=t[j]%i;
		else ta[j]=t[j];
		b+=ta[j];
		if(b>i){
			b-=i;
			tb[j+1]=b;
		}else tb[j+1]=tb[j]+b;
	}
	//cout<<i<<endl;
	//array_show(tb,n+1);
	b=0,c=0,d=(LL)1<<60,e=0;
	for(j=n-1;j>=0;j--){
		d=min(d,tb[j]+c);
		b+=ta[j];
		if(b>=i){
			b-=i;
			d=min(d,c);
			e+=d,c=0,d=(LL)1<<60;
		}
		c+=b;
	}
	return e;
}

int main(){
	LL i,j,k;
	LL pri;
	const LL N=1e6;
	LL s=(LL)1<<60;
	cin>>n;
	for(i=2;i<=N;i++){
		if(np[i])continue;
		for(j=i*i;j<=N;j+=i){
			np[j]=true;
		}
	}
	a=0;
	for(i=0;i<n;i++){
		cin>>t[i];
		a+=t[i];
	}
	if(a==1){
		cout<<-1<<endl;
		return 0;
	}
	pri=a;
	for(i=2;i<=N;i++){
		if(pri<N && !np[pri])break;
		if(a<i)break;
		if(np[i])continue;
		if(a%i)continue;
		while(pri%i==0)pri/=i;
		s=min(s,check(i));
	}
	if(pri>1)s=min(s,check(pri));
	cout<<s<<endl;
}