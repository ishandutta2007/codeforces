#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const LL llinf=9000000000000000000;
const int inf=2000000000;
int a, b;
int arr1[510], arr2[510];
int re=4;
int main()
{
    scanf("%d %d", &a, &b);
    if(a==1&&b==1){
        puts("0");
        return 0;
    }
    if(a==1){
        for(int i=1; i<=b; i++){
            printf("%d ", i+1);
        }
        return 0;
    }
    if(b==1){
        for(int i=1; i<=a; i++){
            printf("%d\n", i+1);
        }
        return 0;
    }
    arr1[1]=1;
    arr1[2]=2;
    arr2[1]=3;
    arr2[2]=4;
    for(int i=3; i<=a; i++)arr1[i]=++re;
    for(int i=3; i<=b; i++)arr2[i]=++re;
    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            printf("%d ", arr1[i]*arr2[j]);
        }
        puts("");
    }
}