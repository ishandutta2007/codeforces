#include<bits/stdc++.h>
using namespace std;
long long int N;
char s[111111];
long long int lowbit(long long int x){
	return x&-x;
}
long long int sim(long long int x,char c){
	if(x <= 0 || x > N)return x;
	if(c == 'L' || c == 'R'){
		long long int w = lowbit(x);
		if(w == 1)return x;
		w /= 2;
		return c == 'L' ? x - w : x + w;
	}
	//c=='U'
	if(x == (N+1)/2)return x;
	long long int w = lowbit(x);
	if(sim(x-w,'R') == x)
		return x-w;
	return x+w;
}
int main(){
	int q;
	long long int pos;
	scanf("%I64d%d",&N,&q);
	while(q--){
		scanf("%I64d%s",&pos,s);
		for(int i=0; s[i]; i++){
			pos = sim(pos,s[i]);
		}
		printf("%I64d\n",pos);
	}
	return 0;
}