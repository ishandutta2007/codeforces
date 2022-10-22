#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char ch[101];
bool f=0;
int main(){
	scanf("%s",ch);
	int len=strlen(ch);
	if(len==1&&ch[0]=='0'){
		printf("0\n");
		return 0;
	}
	if(len%2==0){
		printf("%d\n",len/2);
		return 0;
	}
	for(int i=1;i<len;i++){
		if(f)break;
		if(ch[i]=='1')f=1;
	}
	int ans=(len-1)/2;
	if(f)ans+=1;
	printf("%d\n",ans);
	return 0;
}