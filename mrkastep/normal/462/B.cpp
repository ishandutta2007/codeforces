#include <stdio.h> 
#include <algorithm> 
#include <vector>
#include <math.h>

bool srt(int x,int y){
	if(x>y) return true;
	return false;
}

void solve(int n,int k){
	long long int a[26],i,s,l;
	char c;
	for(i=0;i<26;i++) a[i]=0;
	while(scanf("%c",&c)!=EOF) a[c-'A']++;
	std::sort(a,a+26,srt);
	l=k;
	i=0;
	s=0;
	while(a[i]<l){
		s+=a[i]*a[i];
		l=l-a[i];
		i++;
	}
	s+=l*l;
	printf("%I64d",s);
}

int main(){
#pragma comment (linker,"/STACK:67108864")
#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
#endif
	int n,k;
	scanf("%d%d",&n,&k);
	solve(n,k);
}