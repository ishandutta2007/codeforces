#include<bits/stdc++.h>
using namespace std;
template<class T> inline void read(T &x){
	x=0; register char c=getchar(); register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
const int N=2e5+10;
struct node{
	int x,y;
	inline node operator-(const node &rhs)const{
		return {x-rhs.x,y-rhs.y};
	}
	inline long long operator*(const node &rhs)const{
		return (long long)x*rhs.y-(long long)y*rhs.x;
	}
	inline bool operator<(const node &rhs)const{
		long long tem=(*this)*rhs;
		return tem==0?(x==rhs.x?y<rhs.y:x<rhs.x):tem>0;
	}
	inline bool operator==(const node &rhs)const{
		return x==rhs.x&&y==rhs.y;
	}
}a[N];
int n,m;
set<node> multi;
vector<int> allX,allY;
inline void quit(){puts("Ani"),exit(0);}
vector<int> convex(int l,int r,int ban=-1){
	vector<int> stk;
	auto top=[&](){return a[stk.back()];};
	auto nxt=[&](){return a[stk[stk.size()-2]];};
	for(int i=l;i<=r;i++)if(i!=ban){
		while(stk.size()>1&&(top()-nxt())*(a[i]-nxt())<=0)stk.pop_back();
		stk.push_back(i);
	}
	return stk;
}
int main(){
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i].x),read(a[i].y);
		allX.push_back(a[i].x);
		allY.push_back(a[i].y);
	}
	auto makeSimple=[&](vector<int> &vec){
		sort(vec.begin(),vec.end(),[](int a,int b){return a>b;});
		if(vec.size()&&(vec[0]&1))quit();
		if(vec.size()>1&&(vec[1]&1))quit();
	};
	makeSimple(allX),makeSimple(allY);
	++n,multi.insert({0,0});
	std::sort(a+1,a+n+1);
	for(int i=1;i<n;i++)if(a[i]==a[i+1])multi.insert(a[i]);
	n=std::unique(a+1,a+n+1)-a-1;
	a[n+1].x=a[n+1].y=0;
	vector<int> con=convex(1,n+1);
	for(int i:con)if((a[i].x|a[i].y)&1)quit();
	for(int i=1;i+1<con.size();i++){
		if(multi.count(a[con[i]]))continue;
		vector<int> cur=convex(con[i-1],con[i+1],con[i]);
		for(int i:cur)if((a[i].x|a[i].y)&1)quit();
	}
	puts("Borna");
}