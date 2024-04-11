#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define llinf 8987654321987654321
#define inf 1987654321
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

int n;
int arr[200010];
int sum1, q1, sum2, q2, q;

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        char t;
        scanf(" %c", &t);
        if(t=='?')arr[i]=-1;
        else arr[i]=t-'0';
    }
    for(int i=1; i<=n/2; i++){
        if(arr[i]==-1)q1++;
        else sum1+=arr[i];
    }
    for(int i=n/2+1; i<=n; i++){
        if(arr[i]==-1)q2++;
        else sum2+=arr[i];
    }
    q=q1+q2;
    q/=2;
    if(q1==0&&q2==0){
        if(sum1==sum2)printf("Bicarp");
        else printf("Monocarp");
        return 0;
    }
    if((q1+1)/2*9+sum1>sum2+(q2-(q-(q1+1)/2))*9){
        printf("Monocarp");
        return 0;
    }
    if((q2+1)/2*9+sum2>sum1+(q1-(q-(q2+1)/2))*9){
        printf("Monocarp");
        return 0;
    }
    sum1+=9*q1;
    sum2+=9*q2;
    if(-(q1+1)/2*9+sum1<sum2-(q2-(q-(q1+1)/2))*9){
        printf("Monocarp");
        return 0;
    }
    if(-(q2+1)/2*9+sum2<sum1-(q1-(q-(q2+1)/2))*9){
        printf("Monocarp");
        return 0;
    }
    printf("Bicarp");
}