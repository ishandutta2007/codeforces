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

vector<tuple<LL,LL,LL,LL>> v2;

LL gcd(LL a,LL b){
	if(a<b)swap(a,b);
	if(b==0)return a;
	return gcd(b,a%b);
}

map<pair<LL,LL>,int> m1;

LL check(LL a,LL b){
	LL aa,ab,ac,ba,bb,bc;
	LL p,q,r,s;
	tie(p,q,r,s)=v2[a];
	aa=s-q,ab=p-r;
	ac=aa*p+ab*q;
	tie(p,q,r,s)=v2[b];
	ba=s-q,bb=p-r;
	bc=ba*p+bb*q;
	if(aa==0)swap(aa,ba),swap(ab,bb),swap(ac,bc);
	bb*=aa,bc*=aa;
	bb-=ab*ba,bc-=ac*ba;
	if(bb==0)return 0;
	if(bc%bb!=0)return 0;
	LL x,y;
	y=bc/bb;
	ac-=ab*y;
	if(ac%aa!=0)return 0;
	x=ac/aa;
	aa=0;
	ab=p-x,ac=q-y;
	if(ab!=0)ab/=abs(ab);
	if(ac!=0)ac/=abs(ac);
	if(ab*(r-x)<0 || ac*(s-y)<0 || (p==x && q==y) || (r==x && s==y)){
		aa++;
	}
	tie(p,q,r,s)=v2[a];
	ab=p-x,ac=q-y;
	if(ab!=0)ab/=abs(ab);
	if(ac!=0)ac/=abs(ac);
	if(ab*(r-x)<0 || ac*(s-y)<0 || (p==x && q==y) || (r==x && s==y)){
		aa++;
	}
	if(aa==2 && m1.find(make_pair(x,y))==m1.end()){
		m1[make_pair(x,y)]=1;
		return 1;
	}
	return 0;
}

int main(){
	LL n,m;
	int i,j,k;
	LL a,b,c,d;
	LL s=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a>>b>>c>>d;
		v2.push_back(make_tuple(a,b,c,d));
		s+=gcd(abs(a-c),abs(b-d))+1;
	}
	for(i=0;i<n;i++){
		m1.clear();
		for(j=i+1;j<n;j++){
			s-=check(i,j);
		}
	}
	cout<<s<<endl;
}