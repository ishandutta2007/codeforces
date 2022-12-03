#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

long long b[300010];

long long quick_pow(long long x,long long n){
	long long res = 1;
    long long m=MOD;
	while(n > 0){
		if(n & 1)	res = res * x % m;
		x = x * x % m;
		n >>= 1;
	}
	return res;
}

void init(){
    b[1]=0;
    b[2]=1;
    long long k=1,l=2;
    for(int i=3;i<=300000;i++){
        b[i]=(b[i-1]*2+l-k+MOD)%MOD;
        k=l;
        if (i%2==1) {
            l=(k*2+1)%MOD;
        }
        else {
            l=(k*2)%MOD;
        }
    }
}

int main(){
    long long i,j,k,l,m,n,t,w=0,sum=0;
    int a[300010];
    init();
    string s;
    cin>>m>>n;
    for(i=0;i<m;i++){
        cin>>s;
        for(j=0;j<n;j++) {
            if (s[j]=='*') {
                a[i*n+j]=0;
            }
            else {
                a[i*n+j]=1;
                w++;
            }
        }
    }

    if (w<2) {
        cout<<0;
        return 0;
    }

    for(i=0;i<m;i++) {
        j=0;
        while(j<n) {
            while((j<n)&&(a[i*n+j]==0)) j++;
            k=j;
            while((j<n)&&(a[i*n+j]==1)) j++;
            sum=(sum+b[j-k]*quick_pow(2,w-j+k))%MOD;
        }
    }
    for(j=0;j<n;j++) {
        i=0;
        while(i<m) {
            while((i<m)&&(a[i*n+j]==0)) i++;
            k=i;
            while((i<m)&&(a[i*n+j]==1)) i++;
            sum=(sum+b[i-k]*quick_pow(2,w-i+k))%MOD;
        }
    }
    cout<<sum;
    return 0;
}