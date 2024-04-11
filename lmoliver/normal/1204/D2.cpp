#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100100;
char s[N];
char t[N]={'\0'};
stack<int> x;
int n;
int main(){
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++){
		t[i]='0';
		if(s[i]=='1'){
			x.push(i);
		}
		else{
			if(!x.empty()){
				t[x.top()]='1';
				x.pop();
			}
		}
	}
	printf("%s\n",t);
	return 0;
}