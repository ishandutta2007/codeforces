#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int a[maxn],n,d,ma;
long long sum;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        ma=max(a[i],ma);
        sum+=a[i];
  //      d+=(a[i]%2);
    }

    printf((sum%2==0)&&(ma<=(sum/2))?"YES":"NO");
    /**
    Imagine which kind of sequence can be appeared after such operation
    At first, 1)the sum must be even we will perform exactly that K times
    and Of course,
    2)max element cannot be greater than K
    3) sum is exactly equal to 2*k
    We will show by induction we will have some sequences of operation
    For every sequence at step k+1 and sum equal to 2*k there cannot be more than
    2 positions of k+1 , so we can properly subtract it and regain the sequence
    **/
}