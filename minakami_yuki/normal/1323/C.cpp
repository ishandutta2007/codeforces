#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
const int N=1e6+10;
int n,m,k;
char s[N];
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	int v=0,x;
	for(int i=1;i<=n;++i){
		if(s[i]=='(') --v;
		else ++v;
	}
	if(v!=0) {
		cout<<-1<<endl;
		return 0;
	}
	v=0;x=0;
	for(int i=1;i<=n;++i){
		if(v>0){
			if(s[i]=='(') ++v;
			else --v;
		}
		else if(v==0){
			if(s[i]=='(') ++v;
			else {
				--v;
				++x;
			}
		}
		else{
			++x;
			if(s[i]=='(') ++v;
			else --v;
		}
	}
	cout<<x<<endl;
	return 0;
}