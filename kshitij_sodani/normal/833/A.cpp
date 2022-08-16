#include <iostream>
#define ll long long

using namespace std;
int n,l,r,a,b,mid;
ll c,d,high;
bool k;
int main() {
   
    scanf("%d",&n);

    while(n--){
        scanf("%d%d",&a,&b);
    
        high=(ll)a*b;
        l=1;
        r=1000000;
        k=false;
        while(l<=r){
            mid=(l+r)>>1;
            d=(ll)mid*mid*mid;
            if (d==high) {k=true;break;}
            if (d<high) l=mid+1; else r=mid-1;
        }
        
        k&=(a%mid==0&&b%mid==0);
        (k?puts("Yes"):puts("No"));
    }
    
	return 0;
}