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

string sa;

int check(int pos,int n,bool af=true){
	if(n==1)return pos;
	int i,j,k;
	int a,b,c;
	for(i=0;(1<<i)<=n;i++);
	i--;
	c=pos+(1<<i);
	if(!af)c=pos+n-(1<<i);
	for(i--;i>=0;i--){
		a=c-(1<<i),b=c+(1<<i);
		if(a<pos)a=pos;
		if(b>=pos+n)b=pos+n-1;
		if(a==b)continue;
		cout<<1<<" "<<a<<" "<<b<<endl;
		cin>>sa;
		if(sa[0]=='T')c-=(1<<i);
		else c+=(1<<i);
		c=min(c,pos+n-1);
		c=max(c,pos);
	}
	c=min(c,pos+n-1);
	c=max(c,pos);
	if(c!=pos+n-1){
		cout<<1<<" "<<c<<" "<<c+1<<endl;
		cin>>sa;
		if(sa[0]!='T')c++;
	}
	if(c!=pos){
		cout<<1<<" "<<c<<" "<<c-1<<endl;
		cin>>sa;
		if(sa[0]!='T')c--;
	}
	return c;
}

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n>>m;
	if(n==2){
		cout<<"2 1 2"<<endl;
		return 0;
	}
	a=check(1,n);
	bool af=false;
	if(a<n-a+1){
		if(a!=1){
			cout<<"1 "<<2*a-1<<" 1"<<endl;
			cin>>sa;
			if(sa[0]=='T')af=true;
		}else af=true;
	}else{
		if(a!=n){
			cout<<"1 "<<2*a-n<<" "<<n<<endl;
			cin>>sa;
			if(sa[0]!='T')af=true;
		}
	}
	if(af)b=check(a+1,n-a,true);
	else b=check(1,a-1,false);
	cout<<"2 "<<a<<" "<<b<<endl;
}