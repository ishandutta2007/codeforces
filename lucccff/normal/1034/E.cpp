#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int N=2100000;
ll a[N],b[N];
char A[N],B[N];
int n,bt2[N],bin[22];
 
int main(){
	scanf("%d",&n);
	scanf("%s%s",A,B);
	bin[0]=1;
	for(int i=1;i<=n;++i)bin[i]=bin[i-1]<<1;
	for(int i=0;i<bin[n];++i){
		bt2[i]=bt2[i>>1]+((i&1)<<1);
		a[i]=1ll*(A[i]-'0')<<bt2[i];
		b[i]=1ll*(B[i]-'0')<<bt2[i];
	}
	for(int i=0;i<n;++i)
		for(int j=0;j<bin[n];++j)
			if(bin[i]&j){
				a[j]+=a[j^bin[i]];
				b[j]+=b[j^bin[i]];
			}
	for(int i=0;i<bin[n];++i)a[i]*=b[i];
	for(int i=0;i<n;++i)
		for(int j=0;j<bin[n];++j)
			if(bin[i]&j)
				a[j]-=a[j^bin[i]];
	for(int i=0;i<bin[n];++i)
		putchar((3&(a[i]>>bt2[i]))+'0');
	return 0;
}