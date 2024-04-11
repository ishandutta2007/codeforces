#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int main(){
    scanf("%d",&t);
    while(t--){
    	int a,b,c; scanf("%d %d %d",&a,&b,&c);
    	if(a <= b){
    		int f = b+1-a;
    		if(f > c){
    			puts("0");
    			continue;
    		}
    		c -= f;
    		a += f;
    	}
    	int l=0,r=c;
    	while(l<=r){
    		int mid = (l+r)>>1;
    		if(a+c-mid <= b+mid) r=mid-1;
    		else l=mid+1;
    	}
    	printf("%d\n",l);
    }
}