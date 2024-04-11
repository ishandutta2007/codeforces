#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
struct point{
	int x,y;
	inline point(){
	}
	inline point(int x,int y):x(x),y(y){
	}
	inline point operator - (const point &b)const{
		return point(x-b.x,y-b.y);
	}
	inline bool operator<(const point &b)const{
		if(x==b.x)
			return y<b.y;
		return x<b.x;
	}
	inline bool operator>(const point &b)const{
		if(x==b.x)
			return y>b.y;
		return x>b.x;
	}
	inline bool operator==(const point &b)const{
		return x==b.x&&y==b.y;
	}
};
int Q;
typedef long long LL;
set<point>s;
set<point,greater<point> >s2;
inline LL cross(const point &a,const point &b){
	return 1ll*a.x*b.y-1ll*a.y*b.x;
}
template<class T>
void insert(T &s,const point &a){
	auto i=s.lower_bound(a);
	if(i!=s.end()&&*i==a)
		return;
	auto j=i;
	if(j!=s.begin()){
		j--;
		while(j!=s.begin()){
			auto k=j--;
			if(cross(*k-*j,a-*k)>0)
				break;
			s.erase(k);
		}
	}
	if(i!=s.end()){
		auto k=i;
		while(++i!=s.end()){
			if(cross(*k-a,*i-a)>0)
				break;
			s.erase(k);
			k=i;
		}
	}
	i=s.lower_bound(a);
	if(i==s.end()||i==s.begin())
		s.insert(a);
	else{
		auto j=i--;
		if(cross(a-*i,*j-*i)>0)
			s.insert(a);
	}
}
template<class T>
bool check(const T &s,const point &a){
	auto i=s.lower_bound(a);
	if(*i==a)
		return 1;
	if(i==s.begin()||i==s.end())
		return 0;
	auto j=i--;
	return cross(a-*i,*j-*i)<=0;
}
int main()
{
	Read(Q);
	int p,x,y;
	while(Q--){
		Read(p),Read(x),Read(y);
		if(p==1){
			insert(s,point(x,y));
			insert(s2,point(x,y));
		}
		else
			puts(check(s,point(x,y))&&check(s2,point(x,y))?"YES":"NO");
	}
}