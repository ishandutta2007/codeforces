#include<bits/stdc++.h>
using namespace std;
const int N=1001001;
char s[N];
char ans[N]={'\0'};
int main(){
	scanf("%s",s);
	int n=strlen(s);
	int l=0,r=n-1;
	for(;l+1<r-1;l+=2,r-=2){
		if(s[l]==s[r])ans[l]=ans[r]=s[l];
		else if(s[l+1]==s[r])ans[l+1]=ans[r]=s[l+1];
		else if(s[l]==s[r-1])ans[l]=ans[r-1]=s[l];
		else if(s[l+1]==s[r-1])ans[l+1]=ans[r-1]=s[l+1];
		else exit(1);
	}
	if(l<=r){
		ans[l]=s[l];
	}
	for(int i=0;i<n;i++){
		if(ans[i]){
			printf("%c",ans[i]);
		}
	}
	printf("\n");
	return 0;
}