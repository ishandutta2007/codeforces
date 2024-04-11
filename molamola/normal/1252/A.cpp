#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

char p[301000];
struct point{
	char ch;
	int c;
}w[301000];
int cnt;
int main() {
	int i, c = 0, j;
	scanf("%s",p);
	for(i=0;p[i];i++){
		c++;
		if(p[i]!=p[i+1]){
			w[++cnt] = {p[i],c};
			c = 0;
		}
	}
	if(cnt%2==1){
		int mid = (cnt+1)/2;
		if(w[mid].c >= 2){
			int ck = 0;
			for(i=1;i<mid;i++){
				if(w[mid-i].ch != w[mid+i].ch || w[mid-i].c + w[mid+i].c < 3)ck = 1;
			}
			if(ck==0){
				printf("%d\n",w[mid].c+1);
				return 0;
			}
		}
	}
	puts("0");

	return 0;
}