#include<bits/stdc++.h>
using namespace std;

bool check(int a,int b,int c,int d){
	return a>=0 && b>=0 && c>=0 && d>=0 && (a!=c || b!=d);	
}
int dist(int a,int b,int c,int d){ return max(abs(a-c),abs(b-d)); }
int main(){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	while ((a || b) && (c || d)){
		if ((dist(a-1,b,c,d)<dist(a,b-1,c,d))==(a+b<=c+d)){
			if (check(a-1,b,c,d)) a--; else
			if (check(a,b-1,c,d)) b--; 
		} else{
			if (check(a,b-1,c,d)) b--; else
			if (check(a-1,b,c,d)) a--;
		}
		if (check(a,b,c-1,d-1)){
			c--; d--; continue;
		}
		if ((dist(a,b,c-1,d)<dist(a,b,c,d-1))==(c+d<=a+b)){
			if (check(a,b,c-1,d)){ c--; continue; }
			if (check(a,b,c,d-1)){ d--; continue; }
		} else{
			if (check(a,b,c,d-1)){ d--; continue; }
			if (check(a,b,c-1,d)){ c--; continue; }
		}
	}
	if (!a && !b) puts("Polycarp");
	else puts("Vasiliy");
	return 0;
}