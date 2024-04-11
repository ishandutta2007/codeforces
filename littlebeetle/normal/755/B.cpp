#include<cstdio>
#include<string>
#include<map>
#include<iostream>
using namespace std;
map<string,int>A;
string s;
int n,m,i,c,a,b;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		cin>>s;
		A[s]=1;
	}
	for(i=1;i<=m;i++){
		cin>>s;
		if(A[s])
			c++;
	}
	a=n-c;
	b=m-c;
	if(c%2)
		a++;
	if(a<=b)
		printf("NO");
	else
		printf("YES");
}