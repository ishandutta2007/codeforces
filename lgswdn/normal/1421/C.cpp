#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
using namespace std;
const int N=1e5+9;

char c[N];

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int main() {
	scanf("%s",c+1);
	int n=strlen(c+1);
	printf("3\nR %d\nL %d\nL 2\n",n-1,n);
	return 0;
}