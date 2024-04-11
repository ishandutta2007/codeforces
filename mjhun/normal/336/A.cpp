#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define fst first
#define snd second
using namespace std;

int abs(int a){
	return a>0?a:-a;
}

int sgn(int a){
	return a>0?1:-1;
}

int main(){
	int x,y;
	pair<int,int> p1,p2;
	scanf("%d %d",&x,&y);
	p1=make_pair((abs(x)+abs(y))*sgn(x),0);
	p2=make_pair(0,(abs(x)+abs(y))*sgn(y));
	if(p1.fst>p2.fst){
		printf("%d %d %d %d\n",p2.fst,p2.snd,p1.fst,p1.snd);
	}
	else{
		printf("%d %d %d %d\n",p1.fst,p1.snd,p2.fst,p2.snd);
	}
	return 0;
}