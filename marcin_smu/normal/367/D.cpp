#include<bits/stdc++.h>
using namespace std;
#define make(n) scanf("%d",&n)
#define R(i,n) for(int i=0;i<n;i++)
#define MAX 100100
int d,n,m;
int t[MAX],il[21];
int mb=0;
void dod(int nr){
	il[nr]++;
	if(il[nr]==1){
		mb+= 1<<nr;
	}
}
void us(int nr){
	il[nr]--;
	if(il[nr] == 0){
		mb -= 1<<nr;
	}
}
bool cz[(1<<20)];
main(){
	make(n);make(m);make(d);
	R(i,m){
		int pom;make(pom);
		while(pom--){
			int pom2;make(pom2);pom2--;
			t[pom2] = i;
		}
	}
	R(i,d)dod(t[i]);
	R(i,n-d+1){
		cz[((1<<m)-1)^mb]=1;
		us(t[i]);
		dod(t[i+d]);
	}
	for(int i=(1<<m)-1;i>=0;i--){
		if(cz[i]){
			R(j,m)if(i&(1<<j)){
				cz[i-(1<<j)] = 1;
			}
		}
	}
	int wyn = m+1;
	R(i,(1<<m))if(cz[i]==0)
		wyn = min(wyn,__builtin_popcount(i));
	printf("%d\n",wyn);
}