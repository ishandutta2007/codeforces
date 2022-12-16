#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#if (!defined(__cplusplus) || __cplusplus > 201103)
/**
 * Use scanner in c++14, c++17 or c++20!
 */
template<class T>
struct Scanner{
	int value;
	Scanner(){
		value=0;
		int ch;
		while(isdigit(ch=getchar())){
			value=value*10+(ch^'0');
		}
	}
};
Scanner<int> qaq;
#else
#endif
int x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6;
bool in(int l,double m,int r){
	return l<=m&&m<=r;
}
bool check(double x,double y){
	return in(x1,x,x2)&&in(y1,y,y2)
		&&!(in(x3,x,x4)&&in(y3,y,y4))
		&&!(in(x5,x,x6)&&in(y5,y,y6));
}
void attempt(int x,int y){
	if(check(x+0.5,y+0.5)
	||check(x-0.5,y+0.5)
	||check(x+0.5,y-0.5)
	||check(x-0.5,y-0.5)){
		puts("YES");
		exit(0);	
	}
}
int main(){
	cin>>x1>>y1;
	cin>>x2>>y2;
	cin>>x3>>y3;
	cin>>x4>>y4;
	cin>>x5>>y5;
	cin>>x6>>y6;
	attempt(x1,y1);
	attempt(x1,y2);
	attempt(x1,y3);
	attempt(x1,y4);
	attempt(x1,y5);
	attempt(x1,y6);
	attempt(x2,y1);
	attempt(x2,y2);
	attempt(x2,y3);
	attempt(x2,y4);
	attempt(x2,y5);
	attempt(x2,y6);
	attempt(x3,y1);
	attempt(x3,y2);
	attempt(x3,y3);
	attempt(x3,y4);
	attempt(x3,y5);
	attempt(x3,y6);
	attempt(x4,y1);
	attempt(x4,y2);
	attempt(x4,y3);
	attempt(x4,y4);
	attempt(x4,y5);
	attempt(x4,y6);
	attempt(x5,y1);
	attempt(x5,y2);
	attempt(x5,y3);
	attempt(x5,y4);
	attempt(x5,y5);
	attempt(x5,y6);
	attempt(x6,y1);
	attempt(x6,y2);
	attempt(x6,y3);
	attempt(x6,y4);
	attempt(x6,y5);
	attempt(x6,y6);
	puts("NO");
	return 0;
}