#include<cstdio>
#include<iostream>
using namespace std;
const int a[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,9,25,49};
int i,cnt;
char s[10];
int main(){
	for(i=0;i<19;i++){
		cout<<a[i]<<endl;
		fflush(stdout);
        cin>>s;
        if(s[0]=='y') cnt++;	
	}
	if(cnt>1)
		printf("composite");
	else
		printf("prime");
}