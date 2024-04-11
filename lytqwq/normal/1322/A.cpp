#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
char a[N];
int n,f[N];
/*
*/
int main(){
	scanf("%d",&n);
	scanf("%s",a+1);
	int res=0,lastok=0,befok=1;
	for(int i=1;i<=n;i++){
		if(a[i]=='(')res++;
		else res--;
		if(res<0){
			befok=0;
		}
		if(res==0){
			if(befok){
				f[i]=f[lastok];
			}
			else{
				f[i]=f[lastok]+(i-lastok);
			}
			lastok=i;
			befok=1;
		}
	}
	if(res!=0){
		printf("-1\n");
	}
	else{
		if(befok){
			printf("%d\n",f[lastok]);
		}
		else{
			printf("%d\n",f[lastok]+(n-lastok));
		}
	}
	return 0;
}