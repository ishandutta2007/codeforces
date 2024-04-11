#include<stdio.h>
#include<string.h>
long long int d[22];int ld;
int ff[99][99];
int f(int pos,int max_digit){
	if(ff[pos][max_digit] != -1)return ff[pos][max_digit];
	int res=0;
	for(int i=0; i<=max_digit; i++){
		if(i&(1<<pos))
			res++;
	}
	return ff[pos][max_digit] = res;
}
long long int pw(long long int x,long long int y){
	long long int r=1;
	while(1){
		if(y&1)r*=x;
		if(y>>=1)x*=x;else
			break;
	}
	return r;
}
long long int calc3(int num,int max_digit,int pos){
	if(num < 0)return 1;
	if(pos / 4 >= num){
		return pw(max_digit+1, num);
	}
	return pw(max_digit+1, num-1) * f(pos%4, max_digit);
}
long long int calc2(long long int to, int max_digit, int pos){
	if(to == 0)return 0;
	ld = 0;
	while(to!=0){
		d[ld++] = to % 16;
		to /= 16;
	}
	long long int ret = 0;
	if(pos / 4 < ld)
	for(int i=ld-1; i>=0; i--){
		for(int dig = 0; dig <= max_digit && dig < d[i]; dig++){
			if(pos / 4 == i && !(dig&(1<<(pos%4))))continue;
			ret += calc3(i, max_digit, pos);
		}
		if(d[i] > max_digit)break;
		if(pos / 4 == i && !(d[i]&(1<<(pos%4))))break;
		if(i == 0)
			ret++;
	}
	return ret;
}
long long int calc1(long long int st,long long int en, int max_digit, int pos){
	return calc2(en, max_digit, pos) - calc2(st-1, max_digit, pos);
}
long long int calc(long long int st,long long int en,int i){
	return calc1(st, en, i, i) - calc1(st, en, i-1, i);
}
int main(){
	int q;
	memset(ff,-1,sizeof(ff));
	for(scanf("%d",&q); q--;){
		long long int L,R;
		scanf("%I64x%I64x",&L,&R);
		if(L == 0)L = 1;
		if(L > R){
			puts("0");
			continue;
		}
		long long int ret = 0;
		for(int i=1; i<=15; i++)
			ret += calc(L, R, i);
		printf("%I64d\n",ret);
	}
	return 0;
}