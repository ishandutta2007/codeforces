#include<cstdio>

using namespace std;

int main(){
	int s,v1,v2,t1,t2;
	scanf("%d%d%d%d%d",&s,&v1,&v2,&t1,&t2);
	printf(s*v1+2*t1<s*v2+2*t2?"First\n":s*v1+2*t1>s*v2+2*t2?"Second\n":"Friendship\n");
}