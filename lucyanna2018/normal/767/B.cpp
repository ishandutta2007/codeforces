#include<bits/stdc++.h>
using namespace std;
long long int S,E,L,res,bes;
int n;
void upd(long long int wait, long long int tt){
	if(bes == -1 || bes > wait)
		bes = wait, res = tt;
}
int main(){
	scanf("%I64d%I64d%I64d",&S,&E,&L);
	scanf("%d",&n);
	bes = -1;
	res = -1;
	long long int now = S;
	for(int i=0; i<n; i++){
		long long int tt;
		scanf("%I64d",&tt);
		if(now >= tt){
			if(now + L > E)break;
			long long int wait = now - (tt-1);
			upd(wait, tt-1);
			now += L;
		}else{
			upd(0, now);
			break;
		}
	}
	if(now + L <= E)
		upd(0, now);
	printf("%I64d\n",res);
	return 0;
}