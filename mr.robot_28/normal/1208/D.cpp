#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
long long BIT[N], s[N];
int n;
int ans[N];

void update(int x, int delta){
      for(; x <= n; x += x&-x)
        BIT[x] += delta;
}

long long query(int x){
     long long sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}

int searchNumber(long long prefSum){

    int num = 0;
    long long sum = 0;
    for(int i = 21; i>=0 ; --i){
        if((num + (1<<i) <= n) && (sum + BIT[num + (1<<i)] <= prefSum)){
            num += (1<<i);
            sum += BIT[num];
        }
    }
    return num + 1;
}

int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i){
        update(i, i);
		scanf("%lld", &s[i]);
	}
	for(int i = n; i >= 1; --i){
        ans[i] = searchNumber(s[i]);
        update(ans[i], -ans[i]);
    } 
    for(int i = 1; i <= n; ++i){
        printf("%d", ans[i]);
        if(i < n){
            printf(" ");
        }
        else printf("\n");
    }
}