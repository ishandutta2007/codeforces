#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<deque>
#include<stack>
#include<cmath>
#include<ctime>
#include<complex>
#include<list>
#include<limits.h>
using namespace std;

const int N=105;
int T;
int n,m,k;
int a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		bool flag=true;
		for(int i=1;i<n;i++){
			if(a[i]+k>=a[i+1]){
				m+=a[i]-max(a[i+1]-k,0);
			}else{
				m-=max(a[i+1]-k,a[i])-a[i];
				if(m<0){
					puts("NO");
					flag=false;
					break;
				}
			}
		}
		if(flag) puts("YES");
	}
	return 0;
}