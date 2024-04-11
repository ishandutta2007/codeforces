#include<stdio.h>
#include<map>
using namespace std;
#define ll "I64"

void simulate(long long int n,long long int k){
	if(k==1){
		puts("1");
		return;
	}
	if(n==2){
		puts("2");
		return;
	}
	if(k==2){
		printf("%"ll"d\n",n);
		return;
	}
	k-=2;

	map<long long int,long long int> q;
	q[n-2]=1;
	long long int di = -1;
	while(true){
		long long int minD = (q.rbegin() -> first - 1)/2;
/*		if(minD == 0){
			puts("OOPS");
			return;
		}
*/		long long int tot = 0;
		while(!q.empty() && (q.rbegin() -> first - 1)/2 == minD){
			long long int A = q.rbegin()->first, B = q.rbegin() -> second;
			if(A/2>0)q[A/2] += B;
			if((A-1)/2>0)q[(A-1)/2] += B;
			tot += B;
			q.erase(A);
		}
		if(tot >= k){
			di = minD;
			break;
		}
		k -= tot;
	}

	long long int from = 1, to = n;
	while(true){
		long long int mi = (from+to)/2;
		if((to-from-2)/2 == di){
			if(di == 0){
				if(k == 1)
					printf("%"ll"d\n",(from+to)/2);
				else
					printf("%"ll"d\n",(from+to+1)/2);
			}else
				printf("%"ll"d\n",mi);
			return;
		}
		long long int now = 0;

		q.clear();
		q[mi-from-1] = 1;
		while(true){
			long long int minD = (q.rbegin() -> first - 1)/2;
			if(minD < di)break;
			while(!q.empty() && (q.rbegin() -> first - 1)/2 == minD){
				long long int A = q.rbegin()->first, B = q.rbegin() -> second;
				if(A/2>0)q[A/2] += B;
				if((A-1)/2>0)q[(A-1)/2] += B;
				if(minD == di)
					now += B;
				q.erase(A);
			}
			if(minD <= di)break;
		}

		if(now >= k){
			to = mi;
		}else{
			k -= now;
			from = mi;
		}
	}
}
int main(){
	int _ = 1;
//	scanf("%d",&_);
	for(; _--;){
		long long int n,k;
		scanf("%"ll"d%"ll"d",&n,&k);
		simulate(n,k);
	}
	return 0;
}