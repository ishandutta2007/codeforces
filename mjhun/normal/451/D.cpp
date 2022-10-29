#include <cstdio>
#include <iostream>
using namespace std;

typedef unsigned int uint;

uint d[2][2];
char s[100005];
uint q[100005];

uint r0,r1;

int main(){
	scanf("%s",s);
	int i=0,j,n=0;
	while(s[i]){
		j=i;
		while(s[++j]==s[i]);
		q[n++]=j-i;
		i=j;
	}
	for(i=0;i<n;++i){
		int l=i%2;

		if(q[i]%2){
			r0+=(q[i]/2)*(q[i]/2+1);
			r1+=((q[i]+1)/2)*((q[i]+1)/2);
		}
		else {
			r0+=(q[i]/2)*(q[i]/2);
			r1+=(q[i]/2)*(q[i]/2)+(q[i]/2);
		}
		r0+=d[l][0]*(q[i]/2)+d[l][1]*((q[i]+1)/2);
		r1+=d[l][1]*(q[i]/2)+d[l][0]*((q[i]+1)/2);

		if(q[i]%2){
			swap(d[0][0],d[0][1]);
			swap(d[1][0],d[1][1]);
		}
		
		d[l][0]+=q[i]/2;
		d[l][1]+=(q[i]+1)/2;
	}
	printf("%u %u\n", r0, r1);
	return 0;
}