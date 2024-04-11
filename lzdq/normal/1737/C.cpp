#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
struct Pt{
	int x,y;
	inline void i(){
		scanf("%d%d",&x,&y);
	}
	inline bool cor(){
		return (x==1||x==n)&&(y==1||y==n);
	}
	inline bool c(){
		return x==1||x==n||y==1||y==n;
	}
	inline void fk(){
		x&=1;
		y&=1;
	}
}a,b,c,d;
bool operator ==(Pt a,Pt b){
	return a.x==b.x&&a.y==b.y;
}
bool ans;
inline void chk(Pt p){
	ans=(p.x==d.x||p.y==d.y);
}
int main(){
	//freopen("in1.txt","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		a.i();
		b.i();
		c.i();
		d.i();
		if(a.c()&&b.c()&&c.c()){
			if(a.cor()){
				chk(a);
			}else if(b.cor()){
				chk(b);
			}else if(c.cor()){
				chk(c);
			}
		}else{
			a.fk();
			b.fk();
			c.fk();
			d.fk();
			if(a==d||b==d||c==d) ans=1;
			else ans=0;
		}
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}