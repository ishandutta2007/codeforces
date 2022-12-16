#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200200;
char s[N];
int n;
void GG(){
	puts("No");
	exit(0);
}
void OK(){
	puts("Yes");
	exit(0);
}
int main(){
	scanf("%d",&n);
	scanf("%s",s);
	int c=0;
	for(int i=0;i<n;i++){
		c+=s[i]=='('?1:-1;
	}
	if(c!=0){
		GG();
	}
	c=0;
	for(int i=n-1;i>=0;i--){
		if(s[i]=='('){
			c++;
			s[i]=' ';
			break;
		}
	}
	for(int i=0;i<n;i++){
		if(s[i]=='(')c++;
		if(s[i]==')'&&--c<0)GG();
	}
	OK();
	return 0;
}