#include<bits/stdc++.h>
using namespace std;
bool h[10000];
int d[4],d2[4];
void ask(int x,int y,int&A,int&B){
	int mask = 0;
	A=B=0;
	for(int i=0; i<4; i++){
		d[i] = x%10; x/=10;
		d2[i] = y%10; y/=10;
		if(d[i] == d2[i])A++;
		mask |= 1<<d2[i];
	}
	for(int i=0; i<4; i++)
		if(d[i] != d2[i] && mask&(1<<d[i]))
			B++;
}
bool ok(int x){
	int mask=0;
	for(int i=0; i<4; i++){
		int w = x%10; x/=10;
		if(mask&(1<<w))return true;
		mask|=1<<w;
	}
	return false;
}
int main(){
	for(int j=0; j<10000; j++)
		h[j] = ok(j);
	int cnt = 0, good = 0, A,B,A2,B2;
	while(true){
		while(good < 10000 && h[good])good++;
		assert(good < 10000);
		cnt ++;
		printf("%04d\n", good);
		fflush(stdout);
		scanf("%d%d",&A,&B);
		if(A == 4 && B == 0)break;
		for(int j=0; j<10000; j++)if(!h[j]){
			ask(good, j, A2, B2);
			if(A != A2 || B != B2)
				h[j] = true;
		}
	}
	return 0;
}