#include<bits/stdc++.h>
using namespace std;
const int N=110;
int t,n;
char a[N];
bool f(){
	for(int i=1;i<=n;i++){
		if(a[i]=='?'){
			return 1;
		}
	}
	return 0;
}
int main(){
	scanf("%d",&t);
	for(int io=1;io<=t;io++){
		scanf("%d",&n);
		scanf("%s",a+1);
		int k=0;
		for(int i=1;i<=n;i++){
			if(a[i]=='?'){
				k++;
			}
		}
		if(k==n){
			a[1]='B';
		}
		while(f())
		for(int i=1;i<=n;i++){
			if(a[i]=='B'&&a[i-1]=='?'){
				a[i-1]='R';
			}
			if(a[i]=='R'&&a[i-1]=='?'){
				a[i-1]='B';
			}
			if(a[i]=='B'&&a[i+1]=='?'){
				a[i+1]='R';
			}
			if(a[i]=='R'&&a[i+1]=='?'){
				a[i+1]='B';
			}
		}
		
		printf("%s\n",a+1);
	}
}