#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a;i<b;++i)

double d,r;
int n,s;

int main(){
	scanf("%lf%lf%d",&r,&d,&n);
	fore(_,0,n){
		double x,y,t;
		scanf("%lf%lf%lf",&x,&y,&t);
		double a=hypot(x,y);
		if(a-t>r-d-1e-8&&a+t<r+1e-8)
			s++;
	}
	printf("%d\n",s);
	return 0;
}