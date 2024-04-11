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
int bin[50];
int a[N];
int main(){
	bin[0]=1;for(int i=1;i<=30;++i) bin[i]=bin[i-1]+bin[i-1];
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int x,y;int flag=0;
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		for(int j=30;j>=0;--j){
			x=0;y=0;
			for(int i=1;i<=n;++i){
				//if(j==1)cout<<a[i]<<" "<<bin[j]<<" "<<(a[i]&bin[j])<<endl;
				if(a[i]&bin[j]) ++x;
				else ++y;
			}
			if(x%2==0) continue;
			//cout<<bin[j]<<" "<<x<<" "<<y<<endl;
			if(x%4==1&&y%2==0) flag=1;
			else if(x%4==3&&y%2==0) flag=2;
			else flag=1;
			break;
		}
		if(flag==0) printf("DRAW\n");
		else if(flag==1) printf("WIN\n");
		else printf("LOSE\n");
	}
	return 0;
}