#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define LL long long
using namespace std;
const int N=3e5+10;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n==36){
			cout<<"YES"<<endl;
			cout<<"5 6 10 15"<<endl;
		}
		else if(n==40){
			cout<<"YES"<<endl;
			cout<<"9 6 10 15"<<endl;
		}
		else if(n==44){
			cout<<"YES"<<endl;
			cout<<"6 7 10 21"<<endl;
		}
		else if(n>30){
			cout<<"YES"<<endl;
			printf("%d %d %d %d\n",6,10,14,n-30);
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}