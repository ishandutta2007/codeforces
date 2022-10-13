#include<stdio.h>
int n;
long long int magic,len[222222],tl[222222];
long long int o[111111];
bool simulate(){
	for(int i=1; i<=n; i++)
		if(len[i] > tl[i])
			return false;
	long long int prev_magic = 0, res = 0, now = 0;
	for(int i=1; i<=n; i++){
		long long int L = len[i], T = tl[i];
		if(L <= prev_magic){
			prev_magic -= L;
			now += L;
			continue;
		}
		L -= prev_magic;
		T -= prev_magic;
		now += prev_magic;
		prev_magic = 0;
		if(L * 2 <= T){
			now += L * 2;
			continue;
		}
		long long int X = 2 * L - T;
		now += 2 * (T - L);
		long long int Y = (X-1)/magic + 1;
		if(res + Y <= 100000){
			for(int i=0; i<Y; i++){
				o[res+i] = now + magic * i;
			}
		}
		res += Y;
		prev_magic = Y * magic - X;
		now += X;
	}
	printf("%I64d\n",res);
	if(res <= 100000)
	for(int i=0; i<res; i++)
		printf("%I64d%c",o[i],i<res-1?' ':'\n');
	return true;
}
int main(){
	scanf("%d%I64d",&n,&magic);
	for(int i=1; i<=n; i++)
		scanf("%I64d",&len[i]);
	for(int i=1; i<=n; i++)
		scanf("%I64d",&tl[i]);
	if(!simulate())
		puts("-1");
	return 0;
}