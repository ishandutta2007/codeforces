#include<stdio.h>
#include<string.h>
int n;
char s1[1111],s2[1111];
int cnt1[10],cnt2[10];
int c1[10],c2[10];
int proc1(){
	int res = 0;
	for(int i=0; i<10; i++){
		while(c2[i]--){
			res++;
			for(int j=i; j>=0; j--)
				if(c1[j]){
					--c1[j];
					res--;
					break;
				}
		}
	}
	return res;
}
int proc2(){
	int res = 0;
	for(int i=1; i<10; i++){
		while(c2[i]--){
			for(int j=i-1; j>=0; j--)
				if(c1[j]){
					--c1[j];
					res++;
					break;
				}
		}
	}
	return res;
}
int main(){
	scanf("%d%s%s",&n,s1,s2);
	for(int i=0; i<n; i++){
		cnt1[s1[i]-'0']++;
		cnt2[s2[i]-'0']++;
	}
	memcpy(c1,cnt1,sizeof(c1));
	memcpy(c2,cnt2,sizeof(c2));
	printf("%d\n",proc1());
	memcpy(c1,cnt1,sizeof(c1));
	memcpy(c2,cnt2,sizeof(c2));
	printf("%d\n",proc2());
	return 0;
}